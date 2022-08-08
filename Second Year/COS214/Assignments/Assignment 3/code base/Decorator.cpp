#include "Decorator.h"

Decorator::Decorator() {
    this->section = nullptr;
}

Decorator::~Decorator() {

}

void Decorator::print() {
    if (section != nullptr)
        this->section->print();
}

void Decorator::add(Section * s) {
    if (section == nullptr) {
        section = s;
    } else {
        section->add(s);
    }
}

void Decorator::remove() {
    if (section != nullptr) {
        section = nullptr;
    }
}