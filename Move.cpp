#include "Move.h"
Move::Move()
{

}
Move::Move(string name, string type)
: name_(name), type_(type)
{

}

void Move::setName(string name) {

    name_ = name;


}

string Move::getName() {

    return name_;

}

void Move::setType(string type) {

    type_ = type;


}

string Move::getType() {

    return type_;

}
