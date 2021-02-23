#ifndef PRINT_DOCUMENT_H_
#define PRINT_DOCUMENT_H_

class Print_Document
{
 public:
  int get_size() { return 0; }
  int get_time_stamp() { return 0; }
  bool operator<(const Print_Document& other) {
    return true;
  }
};

