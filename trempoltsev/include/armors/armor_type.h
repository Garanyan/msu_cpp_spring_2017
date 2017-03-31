#pragma once

namespace Arena
{
    namespace Details
    {
        struct ArmorType {};

        struct Chains : public ArmorType {};
        struct Plates : public ArmorType {};
        struct Unarmored : public ArmorType {};
    };
}
