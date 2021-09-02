#include "audiofile.h"

AudioFile::AudioFile(const QString& file)
{
    CompareResult.clear();
    TreeAdded=false;
    QFile tmpfile(file);
    QFileInfo tmp(tmpfile);
    if(!tmpfile.open(QFile::ReadOnly|QFile::Unbuffered))
        QMessageBox::information(0,"Error","Can`t open a file");
    AudioName=tmp.fileName();
    AudioSize=QString::number(tmp.size());
    QByteArray tmpdata=tmpfile.readAll();
    tmpdata.chop(1024);
    tmpdata.remove(0,1024);
    AudioData=QString(tmpdata);
    AudioPath=tmp.absoluteFilePath();
    AudioHash=QString(QCryptographicHash::hash((tmpdata),QCryptographicHash::Md5).toHex());
    tmpfile.flush();
    tmpfile.close();
}

bool AudioFile::operator==(const AudioFile& other) const
{
    return ((*this).AudioName==other.AudioName&&(*this).AudioHash==other.AudioHash&&(*this).AudioSize==other.AudioSize&&(*this).AudioPath==other.AudioPath&&(*this).AudioData==other.AudioData);
}

AudioFile::AudioFile()
{
    AudioHash="";
    AudioName="";
    AudioPath="";
    AudioSize="";
    AudioData="";
    TreeAdded=false;
    CompareResult.clear();
}

bool AudioFile::DataEqual(AudioFile*other) const
{
    return(this->AudioData==other->AudioData);
}

bool AudioFile::PathEqual(AudioFile*other) const
{
    return(this->AudioPath==other->AudioPath);
}

bool AudioFile::HashEqual(AudioFile*other) const
{
    return(this->AudioHash==other->AudioHash);
}

bool AudioFile::SizeEqual(AudioFile*other) const
{
    return(this->AudioSize==other->AudioSize);
}

bool AudioFile::NameEqual(AudioFile*other) const
{
    return(this->AudioName==other->AudioName);
}
