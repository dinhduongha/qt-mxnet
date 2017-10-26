#include "bufferfile.h"

BufferFile::BufferFile(std::string file_path)
        :file_path_(file_path) {
    std::ifstream ifs(file_path.c_str(), std::ios::in | std::ios::binary);
    if (!ifs) {
        length_ = 0;
        buffer_ = NULL;
        return;
    }

    ifs.seekg(0, std::ios::end);
    length_ = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    buffer_ = new char[sizeof(char) * length_];
    ifs.read(buffer_, length_);
    ifs.close();
}

int BufferFile::GetLength() {
    return length_;
}
char* BufferFile::GetBuffer() {
    return buffer_;
}

