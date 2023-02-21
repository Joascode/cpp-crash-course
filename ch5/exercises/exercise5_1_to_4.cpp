#include <array>
#include <cstdio>
struct TransferDetails {
  const long fromAccount;
  const long toAccount;
  const double amount;
};

struct Logger {
  virtual ~Logger() = default;
  virtual void LogTransfer(TransferDetails details) = 0;
};

struct ConsoleLogger : Logger {
  void LogTransfer(TransferDetails details) override {
    printf("[cons] %ld -> %ld: %f\n", details.fromAccount, details.toAccount,
           details.amount);
  }
};

struct FileLogger : Logger {
  void LogTransfer(TransferDetails details) override {
    printf("[file] %ld -> %ld: %f\n", details.fromAccount, details.toAccount,
           details.amount);
  }
};

struct Account {
  long id;
  double amount;
};

struct Transfer {
  const long accountId;
  const double amount;
};

struct AccountDatabase {
  virtual ~AccountDatabase() = default;
  virtual auto RetrieveAmount(long accountId) -> double = 0;
  virtual void SetAmount(Transfer transfer) = 0;
};

struct InMemoryAccountDatabase : AccountDatabase {
  InMemoryAccountDatabase(const Account account1, const Account account2) {
    accounts_[0] = account1;
    accounts_[1] = account2;
  }

  auto RetrieveAmount(const long accountId) -> double override {
    double amount = 0.0;
    std::for_each(accounts_.cbegin(), accounts_.cend(),
                  [&accountId, &amount](Account account) {
                    if (account.id == accountId) {
                      amount = account.amount;
                    }
                  });
    printf("Retrieved %f from %ld\n", amount, accountId);
    return amount;
  }

  void SetAmount(const Transfer transfer) override {
    for (auto &account : accounts_) {
      if (account.id == transfer.accountId) {
        printf("Old amount was: %f\n", account.amount);
        account.amount = transfer.amount;
        printf("New amount is: %f\n", account.amount);
      }
    }
  }

private:
  // I'm assuming here that std::array doesn't need cleaning up, since it
  // doesn't use new?
  std::array<Account, 2> accounts_;
};

struct Bank {
  explicit Bank(Logger &logger, AccountDatabase &accountDB)
      : logger_{logger}, accountDB_{accountDB} {}
  void MakeTransfer(TransferDetails details) {
    const double amount = accountDB_.RetrieveAmount(details.fromAccount);
    if (amount != 0.0 || (amount - details.amount) > 0.0) {
      accountDB_.SetAmount(
          {details.toAccount,
           (accountDB_.RetrieveAmount(details.toAccount) + details.amount)});
      accountDB_.SetAmount({details.fromAccount, amount - details.amount});
      logger_.LogTransfer(details);
    }
  }

private:
  Logger &logger_;
  AccountDatabase &accountDB_;
};

/**
 * @brief Commented out Bank struct is useful for dynamically changing the
 * internally used logger instance from Console to File for example. Since
 * references can't be reseated.
 *
 */
// struct Bank {
//   explicit Bank(Logger *logger) : logger_{logger} {}
//   void MakeTransfer(TransferDetails details) {
//     if (logger_ != nullptr) {
//       logger_->LogTransfer(details);
//     }
//   }
//   void SetLogger(Logger *logger) { logger_ = logger; }

// private:
//   Logger *logger_;
// };

auto main() -> int {
  ConsoleLogger logger;
  InMemoryAccountDatabase account_db{Account{1000, 50.00},
                                     Account{2000, 50.00}};
  Bank bank{logger, account_db};
  // Bank bank{&logger};
  bank.MakeTransfer({1000, 2000, 49.95});
  bank.MakeTransfer({2000, 1000, 20.00});
}
