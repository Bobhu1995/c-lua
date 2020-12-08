local dll = require "mLualib"

local ave, sum = dll.average(1, 2, 3, 4, 5)
print(ave, sum)

dll.sayHello()