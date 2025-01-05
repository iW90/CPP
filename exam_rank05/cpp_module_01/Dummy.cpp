#include "Dummy.hpp"


Dummy::~Dummy() {}
Dummy::Dummy() : ATarget("Target Practice Dummy") {}
Dummy* Dummy::clone() const { return new Dummy(); }