#pragma once

#include <map>
#include <functional>
#include <memory>

namespace isa {
class ievent_s {
public:
  virtual ~ievent_s() {}
};

template <typename Payload> class event_s : public ievent_s {
public:
  using action_u = std::function<Payload>;

  void publish(const Payload &payload) {}

  void subscribe(const action_u &action) {}
};

template <typename Ident> class event_aggregator_s {
public:
  template <typename Event> std::shared_ptr<Event> get_event() {
    Ident id = typename Event::ident;
    auto it = map_.find(id);
    if (it != map_.end()) {
      return (*it).second;
    }
    auto new_event = std::shared_ptr<Event>(new Event());
    map_.insert(std::make_pair(id, new_event));
    return new_event;
  }

private:
  std::map<Ident, std::shared_ptr<event_s>> map_;
};
}
