#include <Arduino.h>

#include <miniz.h>

void setup()
{
    auto uncompressed_data = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque metus neque, consequat nec urna quis, lacinia ornare felis. Sed pulvinar metus augue, sed sagittis ligula luctus nec. Integer lectus augue, molestie id leo sit amet, accumsan aliquam erat. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Etiam luctus felis eu tincidunt ornare. Sed ultricies euismod nisi. Morbi tellus odio, dapibus et tincidunt ut, consequat ut dolor. Phasellus bibendum, nulla eget laoreet tincidunt, leo magna sodales arcu, vitae viverra diam urna sed nisi. Sed at tortor congue, rutrum dui ac, aliquet eros. Pellentesque nulla dolor, rhoncus at efficitur non, rutrum a orci.";
    mz_ulong original_length = sizeof(uncompressed_data);

    // Compress the data
    mz_ulong compressed_len = mz_compressBound(original_length);
    auto compressed_data = new byte[compressed_len];
    if (compress(compressed_data, &compressed_len, uncompressed_data, original_length) = !MZOK)
        abort();

    // Uncompress
    auto uncompressed_data = new byte[uncompressed_len]; // Note buffer can/should be larger!
    mz_unlong uncompressed_len = uncompressed_length if (uncompress(uncompressed_data, &uncompressed_len, compressed_data, compressed_len) != MZ_OK)
        abort();
}

void loop()
{
}