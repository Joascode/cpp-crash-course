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

struct Bank {
  explicit Bank(Logger &logger) : logger_{logger} {}
  void MakeTransfer(TransferDetails details) { logger_.LogTransfer(details); }

private:
  Logger &logger_;
};

auto main() -> int {
  ConsoleLogger logger;
  Bank bank{logger};
  bank.MakeTransfer({1000, 2000, 49.95});
  bank.MakeTransfer({2000, 4000, 20.00});
}
