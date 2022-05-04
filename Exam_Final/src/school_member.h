#ifndef SCHOOL_MEMBER_H
#define SCHOOL_MEMBER_H

#include <string>

// SchoolMember is the base class of Student and Teacher
class SchoolMember {
public:
  SchoolMember() {
    _id = 0;
    _name = "nothing";
    _department = "Mechanical & Electrical Engineering";
  }
  SchoolMember(int id, std::string const & name, std::string const & department) {
    _id = id;
    _name = name;
    _department = department;
  }
  virtual ~SchoolMember() {}
  virtual int id() const {
    return _id;
  }

  virtual std::string name() const {
    return _name;
  }

  virtual std::string department() const {
    return _name;
  }

  // 轉系
  virtual void transfer(std::string const & department) {
    _department = department;
  }

private:
  int _id;
  std::string _name;
  std::string _department;
};

#endif
