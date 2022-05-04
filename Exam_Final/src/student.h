#ifndef STUDENT_H
#define STUDENT_H

#include <numeric>  // std::accumulate
#include <stdexcept>  // std::out_of_range, std::range_error
#include <string>
#include <vector>

#include "school_member.h"

class Student : public SchoolMember {
public:
  Student() {
    _id = 0;
    _name = "nothing";
    _department = "Mechanical & Electrical Engineering";
  }
  Student(int const id, std::string const & name, std::string const & department = "Mechanical & Electrical Engineering") {
    _id = id;
    _name = name;
    _department = department;
  }

  ~Student() override {}

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

  void addScore(double const score)  {
    _scores.push_back(score);
  }

  double getScore(int const number_of_test) const {
    if (number_of_test > _scores.size()) {
      throw std::out_of_range("NO_SUCH_NUMBER_OF_TEST");
    } else {
      return _scores[number_of_test-1];
    }
  }

  double scoreAverage() const {
    if (_scores.size() == 0) {
      throw std::range_error("ERROR: NO_SCORE");
    } else {
      double sum = 0;
      double avg = 0;
      for (int i = 0 ; i < _scores.size(); i++) {
        sum += _scores[i];
      }
      avg = sum / _scores.size();
      return avg;
    }
  }

private:
  int _id;
  std::string _name;
  std::string _department;
  std::vector <double> _scores;
};

#endif
