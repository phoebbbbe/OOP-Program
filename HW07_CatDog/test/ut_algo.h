#include "../src/algo.h"
#include "../src/cat.h"
#include "../src/dog.h"
#include "../src/pet.h"

class AlgoTest: public ::testing::Test {
protected:
    std::vector <Pet *> _pets;
};

TEST_F(AlgoTest, petsTest) {
    _pets.push_back(new Cat("Lucky", 2.5));
    _pets.push_back(new Dog("Doggy", 33));
    _pets.push_back(new Cat("FatAmy", 5.9));
    ASSERT_EQ(_pets[0]->name(), "Lucky");
    ASSERT_NEAR(_pets[0]->weight(), 2.5, 0.001);
    ASSERT_EQ(_pets[1]->name(), "Doggy");
    ASSERT_NEAR(_pets[1]->weight(), 33, 0.001);
    ASSERT_EQ(_pets[2]->name(), "FatAmy");
    ASSERT_NEAR(_pets[2]->weight(), 5.9, 0.001);
    for (int i = 0; i < _pets.size(); i++) {
        delete _pets[i];
    }
}

TEST_F(AlgoTest, petsTest2) {
    _pets.push_back(new Cat("Lucky", 2.5));
    _pets.push_back(new Dog("Doggyy", 33));
    _pets.push_back(new Cat("FatAmyyy", 5.9));
    ASSERT_EQ((*maxPet(_pets.begin(), _pets.end(), pet_comp::longerName))->name(),"FatAmyyy");
    ASSERT_NEAR((*maxPet(_pets.begin(), _pets.end(), pet_comp::largerWeight))->weight(), 33, 0.001);
    for (int i = 0; i < _pets.size(); i++) {
        delete _pets[i];
    }
}

TEST_F(AlgoTest, petsTest3) {
    _pets.push_back(new Cat("aaaaaa", 4));
    _pets.push_back(new Cat("bbb", 5.9));
    _pets.push_back(new Cat("cc", 5));
    ASSERT_EQ((*maxPet(_pets.begin(), _pets.end(), pet_comp::longerName))->name(),"aaaaaa");
    ASSERT_NEAR((*maxPet(_pets.begin(), _pets.end(), pet_comp::largerWeight))->weight(), 5.9, 0.001);
    for (int i = 0; i < _pets.size(); i++) {
        delete _pets[i];
    }
}

TEST_F(AlgoTest, petsTest4) {
    _pets.push_back(new Dog("ddddd", 44));
    _pets.push_back(new Cat("eee", 4));
    _pets.push_back(new Cat("ff", 5.5));
    ASSERT_EQ((*maxPet(_pets.begin(), _pets.end(), pet_comp::longerName))->name(),"ddddd");
    ASSERT_NEAR((*maxPet(_pets.begin(), _pets.end(), pet_comp::largerWeight))->weight(), 44, 0.001);
    for (int i = 0; i < _pets.size(); i++) {
        delete _pets[i];
    }
}