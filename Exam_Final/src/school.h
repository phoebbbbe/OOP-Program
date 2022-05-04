#ifndef SCHOOL_H
#define SCHOOL_H

#include <vector>

#include "school_member.h"

class School : public SchoolMember {
public:
  School() {}

  void addSchoolMember(SchoolMember * const member) {
    _schoolmembers.push_back(member);
  }

  SchoolMember* at(int index) const {
        return _schoolmembers[index];
  }
  
  template<typename Condition>
  std::vector<SchoolMember *> getSchoolMemberWithCondition(Condition cond) {
    std::vector<SchoolMember *> school_member_in_cond;
    for (int i = 0; i < this->_schoolmembers.size(); i++) {
        if (cond(_schoolmembers[i])) {
          school_member_in_cond.push_back(_schoolmembers[i]);
        }
      }
    return school_member_in_cond;
  }


private:
  std::vector <SchoolMember *> _schoolmembers;
};

#endif
