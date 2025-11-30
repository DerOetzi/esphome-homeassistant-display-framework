#pragma once

#include "esphome.h"
#include <vector>
#include <string>

namespace esphome {

struct NotificationEntry {
  std::string id;
  std::string text;
};

class NotificationManager {
 public:
  static NotificationManager &instance() {
    static NotificationManager instance;
    return instance;
  }

  void rotate() {
    if (notifications_.empty()) {
      return;
    }
    if (notifications_.size() == 1) {
      return;
    }
    current_index_ = (current_index_ + 1) % notifications_.size();
    dirty_ = true;
  }

  void add_notification(const std::string &id, const std::string &text) {
    for (auto &n : notifications_) {
      if (n.id == id) {
        n.text = text;
        dirty_ = true;
        return;
      }
    }
    NotificationEntry e;
    e.id = id;
    e.text = text;
    notifications_.push_back(e);
    if (notifications_.size() == 1) {
      current_index_ = 0;
    }
    dirty_ = true;
  }

  void remove_notification(const std::string &id) {
    for (size_t i = 0; i < notifications_.size(); i++) {
      if (notifications_[i].id == id) {
        notifications_.erase(notifications_.begin() + i);
        if (current_index_ >= notifications_.size()) {
          current_index_ = 0;
        }
        dirty_ = true;
        break;
      }
    }
  }

  bool has_notifications() const {
    return !notifications_.empty();
  }

  std::string get_current_text() const {
    if (notifications_.empty()) {
      return "";
    }
    return notifications_[current_index_].text;
  }

  bool is_dirty() const {
    return dirty_;
  }

  void clear_dirty() {
    dirty_ = false;
  }

 private:
  NotificationManager() = default;
  NotificationManager(const NotificationManager &) = delete;
  NotificationManager &operator=(const NotificationManager &) = delete;

  std::vector<NotificationEntry> notifications_;
  size_t current_index_{0};
  bool dirty_{true};
};

}  // namespace esphome
