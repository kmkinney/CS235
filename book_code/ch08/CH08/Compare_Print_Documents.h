#ifndef COMPARE_PRINT_DOCUMENTS_H
#define COMPARE_PRINT_DOCUMENTS_H

#include "Print_Document.h"

class Compare_Print_Documents
{
 public:

  bool operator()(const Print_Document& left,
		  const Print_Document& right) {
    return order_value(left) > order_value(right);
  }

 private:

  static const double P1 = 1.0;
  static const double P2 = 0.001;

  double order_value(const Print_Document& pd) {
    return P1 * pd.get_size() + P2 * pd.get_time_stamp();
  }

};

#endif
