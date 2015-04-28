////////////////////////////////////////////////////////////
//
// MiraiProject
// Copyright (C) 2014-2015 CORTIER Benoît (benoit.cortier@gmail.com), BOULMIER Jérôme (jerome.boulmier@outlook.fr)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#include <vector>

#include "MiraiProject/stat/ModifiedStat.hpp"
#include "MiraiProject/stat/VitalStat.hpp"

mp::VitalStat::VitalStat() :    ModifiedStat(),
                                curValue_ { 0 }
{
    // constructor
}

mp::VitalStat::~VitalStat()
{
    // destructor
}

int mp::VitalStat::getCurValue()
{
    if(curValue_ > ModifiedStat().adjustedBaseValue())
        curValue_ = ModifiedStat().adjustedBaseValue();

    return curValue_;
}

void mp::VitalStat::setCurValue(int curValue)
{
    if(curValue > ModifiedStat().adjustedBaseValue())
        curValue = ModifiedStat().adjustedBaseValue();

    curValue_ = curValue;
}