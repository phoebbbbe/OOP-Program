#ifndef Pet_H
#define Pet_H
class Pet {
public:
    Pet() {
        _name = "nothing";
        _weight = 0;
    }
    Pet(std::string name, double weight) {
        _name = name;
        _weight = weight;
    }

    virtual ~Pet() {}
    virtual std::string name() const {
        return _name;
    }

    virtual double weight() const {
        return _weight;
    }

    virtual void feed() = 0;

protected:
    std::string _name;
    double _weight;
};
#endif