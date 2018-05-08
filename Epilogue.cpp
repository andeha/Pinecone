//
//  Epilogue.cpp
//  Pinecone Unit Tests
//

#include <Pinecone.h>

/*

 An — on Intel x86_64 — redundant file; See [Pinecone]-[System]-[macOS]>--<
   AppSymbols.h|cpp>{AppSymbols::symbols(...}.
 
 */

#define PROLOGUE ADD_UNITTEST
#define EPILOGUE ADD_UNITTEST

BEGIN_UNITTESTS
    // BitTests.cpp
    ADD_UNITTEST(Bittest_glassAndWrench)
    ADD_UNITTEST(Bittest_shift)
    ADD_UNITTEST(Bittest_toggle)
    // ExceptionTests.cpp
    ADD_UNITTEST(Exception_1)
    ADD_UNITTEST(Exception_2)
    // MemoryTests.cpp
    ADD_UNITTEST(Memory_1)
    // MallocTests.cpp
    ADD_UNITTEST(MallocFree_1)
    // PrintfTests.cpp
    ADD_UNITTEST(Printf_1)
    ADD_UNITTEST(Printf_2)
    ADD_UNITTEST(Printf_3)
    ADD_UNITTEST(Printf_4)
    ADD_UNITTEST(Printf_5)
    ADD_UNITTEST(Printf_6)
    // MemoryRegionTests.cpp
    ADD_UNITTEST(MemoryRegionGrowth_1)
    ADD_UNITTEST(MemoryRegionAbduct_1)
    ADD_UNITTEST(MemoryRegionReflect_1)
    // PageSize.cpp
    ADD_UNITTEST(SystemInfoPageSize_1)
    // MathTests.cpp
    ADD_UNITTEST(Relative_1)
    ADD_UNITTEST(Abs_1)
    ADD_UNITTEST(Abs_2)
    ADD_UNITTEST(Abs_3)
    ADD_UNITTEST(Inf_1)
    ADD_UNITTEST(Nan_1)
    ADD_UNITTEST(Neg_1)
    ADD_UNITTEST(Modf_1)
    ADD_UNITTEST(Exp_1)
    ADD_UNITTEST(Ln_1)
    ADD_UNITTEST(Pow_1)
    ADD_UNITTEST(Modf_1)
    ADD_UNITTEST(Sqrt_1)
    ADD_UNITTEST(Arctan_1)
    ADD_UNITTEST(Sincos_1)
    ADD_UNITTEST(Floor_1)
    ADD_UNITTEST(Cast_1)
    // BaseTests.cpp
    ADD_UNITTEST(BaseUnsigned_1)
    ADD_UNITTEST(BaseSigned_1)
    ADD_UNITTEST(BaseSigned_2)
    ADD_UNITTEST(BaseSigned_3)
    // RandomTests.cpp
    ADD_UNITTEST(IntegerRandom_1)
    // StringTests.cpp
    ADD_UNITTEST(String_constants)
    ADD_UNITTEST(String_dereference1)
    ADD_UNITTEST(String_dereference2)
    ADD_UNITTEST(String_dereference3)
    ADD_UNITTEST(String_unicode1)
    ADD_UNITTEST(String_unicode2)
    ADD_UNITTEST(String_incorporate)
    ADD_UNITTEST(String_merge)
    ADD_UNITTEST(String_appendMemoryRegion)
    ADD_UNITTEST(String_appendchar)
    // VectorTests.cpp
    ADD_UNITTEST(Vector_1)
    ADD_UNITTEST(Vector_2)
    ADD_UNITTEST(Vector_3)
    //ADD_UNITTEST(Vector_4)
    // MapTests.cpp
    ADD_UNITTEST(Map_EightBit)
    ADD_UNITTEST(Map_Unicode)
    // UnicodesTests.cpp
    ADD_UNITTEST(Unicodes_prefix_1)
    ADD_UNITTEST(Unicodes_prefix_2)
    ADD_UNITTEST(Unicodes_is_1)
    ADD_UNITTEST(Unicodes_codeToName)
    ADD_UNITTEST(Unicodes_nameToCode)
    // Utf8Tests.cpp
    ADD_UNITTEST(Utf8_Utf8ToUnicode_1)
    ADD_UNITTEST(Utf8_UnicodeToUtf8_1)
    ADD_UNITTEST(Utf8_Utf8TraverseNullterminated_1)
    // UnicodeTests.cpp
    ADD_UNITTEST(Unicode_traverse_1)
    ADD_UNITTEST(Unicode_equality)
    // DecoratedTests.cpp
    ADD_UNITTEST(Decorated_1)
    // Utf8TerminalTests.cpp
    ADD_UNITTEST(Utf8Terminal_1)
    // ReflectionTests.cpp
    ADD_UNITTEST(Reflection_1)
    /* Unit Tests for Additions */
    // Formatting.hpp
    ADD_UNITTEST(TreeFormatting_1)
    ADD_UNITTEST(TableFormatting_1)
    // Helpers.cpp
    // Chronology.cpp
    ADD_UNITTEST(Chronology_static)
    ADD_UNITTEST(Chronology_UTC)
    ADD_UNITTEST(Chronology_singularconsensus)
    ADD_UNITTEST(Chronology_now)
    ADD_UNITTEST(Chronology_date)
    ADD_UNITTEST(Chronology_midnight)
    ADD_UNITTEST(Chronology_increment)
    ADD_UNITTEST(Chronology_dayOfWeek)
    ADD_UNITTEST(Chronology_move)
    ADD_UNITTEST(Chronology_easter)
    ADD_UNITTEST(Chronology_leap)
    ADD_UNITTEST(Chronology_monotonicallyIncreasing)
    ADD_UNITTEST(Chronology_ordinal)
    ADD_UNITTEST(Chronology_onetzconsensus)
    ADD_UNITTEST(Chronology_twotz)
    // SlowRandom.cpp
    // Arithmetics.cpp
    // Mathematics.cpp
    // Subgraph.cpp
    // Bezier.cpp
    // Guid.cpp
    // Base6432.cpp
    ADD_UNITTEST(Base64_1)
    ADD_UNITTEST(Base32_1)
    // Compression.cpp
    // Security.cpp
    // Interleave.cpp
    // FontRasterizer.cpp
    ADD_UNITTEST(Rasterizer_Outline)
    ADD_UNITTEST(Rasterizer_Monocrome)
    ADD_UNITTEST(Rasterizer_Antialiased256Grayscales)
    // Parsers.cpp
    // ModernIntel.cpp
    // MoreMaths.cpp
    // Task.cpp
    ADD_UNITTEST(Task_1)
    ADD_UNITTEST(Task_2)
    ADD_UNITTEST(Task_3)
    // Performance.h
    // Timeserie.hpp
    ADD_UNITTEST(Timeserie_1)
    // ComputationalIndex.cpp
    ADD_UNITTEST(ComputationalIndex_1)
    // UQLParser.cpp
    ADD_UNITTEST(UQL_1)
END_UNITTESTS
