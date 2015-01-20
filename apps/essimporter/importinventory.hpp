#ifndef OPENMW_ESSIMPORT_IMPORTINVENTORY_H
#define OPENMW_ESSIMPORT_IMPORTINVENTORY_H

#include <vector>
#include <string>

#include <components/esm/cellref.hpp>

namespace ESM
{
    class ESMReader;
}

namespace ESSImport
{

    struct Inventory
    {
        struct InventoryItem : public ESM::CellRef
        {
            std::string mId;
            int mCondition;
        };
        std::vector<InventoryItem> mItems;

        void load(ESM::ESMReader& esm);
    };

}

#endif