/******* PRIORITY QUEUE *******
Supported: push(), top(), pop(). No middle search or modify the value.
 ******************************/

#include <queue>

struct Meeting {
  Meeting(int start_time, int end_time, string abc)
      : start(start_time), end(end_time), str(abc) {}
  int start;
  int end;
  string str;
};

struct MeetingCmp {
  // order: 1 -> 2 -> 3
  bool operator()(const Meeting& lhs, const Meeting& rhs) {
    return lhs.start > rhs.start;
  }
};

std::priority_queue<Meeting, std::vector<Meeting>, MeetingCmp> pq;

pq.emplace(Meeting(5, 10, "first"));
pq.push(Meeting(2, 12, "b"));
pq.emplace(5, 10, "second");
auto f = pq.top();  // This return const&, if we need to modify use pointer
pq.pop();
