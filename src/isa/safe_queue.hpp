#pragma once

#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>

namespace isa::safe {
template <typename T> class Safe_queue {
public:
  Safe_queue() {}
  Safe_queue(const Safe_queue<T> &other) { q_ = other.q_; }

  void push(const T &elem) {
    std::lock_guard<std::mutex> l(mutex_);
    q_.push(elem);
    cv_.notify_one();
  }

  void wait_and_pull(T &elem) {
    std::unique_lock<std::mutex> l(mutex_);
    cv_.wait(l, [this] { return !q_.empty(); });
    elem = q_.front();
    q_.pop();
  }

  bool try_pull(T &elem) {
    std::lock_guard<std::mutex> l(mutex_);
    if (q_.empty()) {
      return false;
    }
    elem = q_.front();
    q_.pop();
    return true;
  }

  bool empty() const {
    std::lock_guard<std::mutex> l(mutex_);
    return q_.empty();
  }

private:
  std::queue<T> q_;
  std::mutex mutex_;
  std::condition_variable cv_;
};
} // namespace isa::safe
