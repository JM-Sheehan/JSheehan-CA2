#include "PickUpCmpt.hpp"

PickUpCmpt::PickUpCmpt(Type type) {
	m_type = type;
}

PickUpCmpt::~PickUpCmpt() {
	active = false;
}