#include "item.hpp"
#include "methods.hpp"

Item::Item()
{
  key = -1;
}

Item::~Item() {}

int Item::getKey()
{
  return key;
}

void Item::generate(int val)
{
  key = val;
}

void Item::gentest(int val)
{
  key = generateKey(val);
}

void Item::setKey(int val)
{
  key = val;
}