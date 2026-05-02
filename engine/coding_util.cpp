void PutFixed32(std::string* dst, uint32_t value) {
    char buf[sizeof(value)];
    // We are copying the bytes at the location of the uint_32 into the char array buffer, so that the int is stored as its raw bytes
    // We use memcpy to avoid alignment issues
    std::memcpy(buf, &value, sizeof(value));
    dst->append(buf, sizeof(buf));
}

uint32_t DecodeFixed32(std::string* str) {
    if (str->length() < 4) return 0;
    uint32_t first_four_int;

    std::memcpy(&first_four_int, str->data(), sizeof(first_four_int));

    str->erase(0, 4);

    return first_four_int;
}