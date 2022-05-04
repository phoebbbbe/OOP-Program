#ifndef TEACHER_H
#define TEACHER_H

#include <algorithm>  // std::find_if
#include <stdexcept>  // std::domain_error, std::range_error
#include <string>
#include <vector>

#include "school_member.h"
#include "student.h"

class Teacher : public SchoolMember {
public:
Teacher() {
    _id = 0;
    _name = "nothing";
    _department = "Mechanical & Electrical Engineering";
  }
  Teacher(int const id, std::string const & name, std::string const & department = "Mechanical & Electrical Engineering") {
    _id = id;
    _name = name;
    _department = department;
  }
  
  ~Teacher() override {}

  int id() const override {
    return _id;
  }

  std::string name() const override {
    return _name;
  }

  std::string department() const override {
    return _department;
  }

  // 轉系
  void transfer(std::string const & department) override {
    _department = department;
  }

  // Don't have to handle duplicate ids.
  void addStudent(Student const & stu) {
    if (stu.department() != this->department()) {
      throw std::domain_error("ERROR: NOT_IN_THE_SAME_DEPARTMENT");
    } else {
      _students.push_back(stu);
    }
  }

  Student getStudentById(int const id) const {
    // If you don't know how to use the capture clause, which is the [],
    // you can use a functor and set the id into it before passing.
    Student tmpStu;
    for (int i = 0 ; i < _students.size(); i++) {
      if (_students[i].id() == id) {
        tmpStu = Student(_students[i].id(), _students[i].name(), _students[i].department());
        return tmpStu;
      }
    }
    throw std::range_error("ERROR: STUDENT_NOT_EXIST");
  }

private:
  int _id;
  std::string _name;
  std::string _department;
  std::vector <Student> _students;
};

#endif
