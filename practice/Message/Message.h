#ifndef MESSAGE_H
#define MESSAGE_H

#include <set>
#include <string>

class Folder;

class Message {
  friend class Folder;
  friend void swap(Message &, Message &);

public:
  explicit Message(const std::string &str = "") : contents(str) {}
  Message(const Message &);
  Message(Message &&);
  Message &operator=(const Message &);
  Message &operator=(Message &&);
  ~Message();
  void save(Folder &);
  void remove(Folder &);
  void move_Folders(Message *);

private:
  std::string contents;
  std::set<Folder *> folders;
  void add_to_Folders(const Message &);
  void remove_from_Folders();
};

#endif // !MESSAGE_H
