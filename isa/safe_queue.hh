#pragma once

#include <queue>
#include <mutex>
#include <memory>
#include <condition_variable>

namespace isa {
namespace safe {
template <typename T> class safe_queue_s {
public:
  safe_queue_s() {}

  safe_queue_s(const safe_queue_s<T> &other) { q_ = other.q_; }

  void push(const T &elem) {
    std::lock_guard<std::mutex> l(mutex_);
    q_.push(elem);
    var_.notify_one();
  }

  void wait_and_pull(T &elem) {
    std::unique_lock<std::mutex> l(mutex_);
    var_.wait(l, [this] { return !q_.empty(); });
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
  std::condition_variable var_;
};
}
}
