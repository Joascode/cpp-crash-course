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

struct AccountDatabase {
  virtual ~AccountDatabase() = default;
  virtual auto RetrieveAmount(long accountId) -> double = 0;
  virtual void SetAmount(long accountId) = 0;
};

struct Bank {
  explicit Bank(Logger &logger) : logger_{logger} {}
  void MakeTransfer(TransferDetails details) { logger_.LogTransfer(details); }

private:
  Logger &logger_;
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
  Bank bank{logger};
  // Bank bank{&logger};
  bank.MakeTransfer({1000, 2000, 49.95});
  bank.MakeTransfer({2000, 4000, 20.00});
}
