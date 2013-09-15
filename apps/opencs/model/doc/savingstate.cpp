
#include "savingstate.hpp"

#include "operation.hpp"
#include "document.hpp"

CSMDoc::SavingState::SavingState (Operation& operation)
: mOperation (operation),
   /// \todo set encoding properly, once config implementation has been fixed.
  mEncoder (ToUTF8::calculateEncoding ("win1252"))
{
    mWriter.setEncoder (&mEncoder);
}

bool CSMDoc::SavingState::hasError() const
{
    return mOperation.hasError();
}

void CSMDoc::SavingState::start (Document& document)
{
    if (mStream.is_open())
        mStream.close();

    mStream.clear();

    mPath = document.getSavePath();

    boost::filesystem::path file (mPath.filename().string() + ".tmp");

    mTmpPath = mPath.parent_path();

    mTmpPath /= file;
}

const boost::filesystem::path& CSMDoc::SavingState::getPath() const
{
    return mPath;
}

const boost::filesystem::path& CSMDoc::SavingState::getTmpPath() const
{
    return mTmpPath;
}

std::ofstream& CSMDoc::SavingState::getStream()
{
    return mStream;
}

ESM::ESMWriter& CSMDoc::SavingState::getWriter()
{
    return mWriter;
}