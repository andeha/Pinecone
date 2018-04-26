
# Pinecone with Additions

Welcome to *Pinecone*, the library operating system for your next internet of things project, embedded experiment or robotics prototype. The library comprises of a run-time with:

- Dynamically resizable memory regions
- Unicode-, utf-8 and decorated strings (and terminal I/O for decorated strings)
- Memory-mapped files (`abduct` and `reflect`)
- The *pimpl* idiom, `Optional` and `Tuple` classes
- Slim `Vector` and `Map` container templates
- Reflection API

And...

### Pinecone Additions 

With additional features such as:

- Chronologies, calendars and instants
- Well-defined helper functions such as `Frame`,  `IsPowerOfTwo`, `Roman` and `HowMany`
- Random integers, series of random integers and uniform- or normally distributed random floating-points
- Formatting tables (`PresentTable`) and trees (`TreePresenter`)
- Graphs (as in *graph theory*)
- Time series, percentiles and histograms 
- Linear programs, FFT and computational geometry
- Bezier paths and rasterization

## Examples

To get a feeling for how to use the API's, please scan through the following examples. 

To create Unicode® strings:

    String space = StringLiteral(" ");
    String s = StringLiteral("%s%S%s", "prefix", *space, "suffix");
    Tuple<String, String> partsRef = s.attach(6); 
    Tuple<String, String> partsCopy = s.detach(6);
    String refClone = String::merge(Get<1>(partsRef), Get<0>(partsRef), true);
    String refCopy = String::merge(Get<1>(partsRef), Get<0>(partsRef), false);  
    String copyClone = String::merge(Get<1>(partsCopy), Get<0>(partsCopy), true);
    String copyCopy = String::merge(Get<1>(partsCopy), Get<0>(partsCopy), false); 
    String copy = s.clone();
    copy.append(copy);
    copy.append(" period.");

To insert and delete a substring:

    String nihao = StringLiteral("ni hao");    
    String aloha = StringLiteral("Aloha, ");
    aloha.incorporate(6, nihao);
    aloha.exclude(5, 1); // Exclude comma

To print to the console (on macOS) or on UART5 (on PIC32MX/MZ):

    Termlog << eol << "Hello" << tab << "world" << sep;
    printf(" - Mr. Pinecone");

To create an amorphous memory area, write:

    Optional<MemoryRegion> file = MemoryRegion::abduct(1024*1024);
    if (MemoryRegion *region = file.query()) {
        uint64_t *p = (uint64_t *)region->pointer(0);
        *p = 0x12;
        __builtin_int_t outsize = region->bytes();
    }

To open a Utf-8 file, write: 

    Optional<MemoryRegion> file = MemoryRegion::reflect("/tmp/utf8_text.txt");
    if (MemoryRegion *region = file.query()) {
        const char *p = (const char *)region->pointer(12 /* bytes */);
        printf("%s, size: %d, %x, %b", p, region->bytes(), region->bytes(), region->bytes());
    }

To open a Unicode file, write:

    Optional<MemoryRegion> file = MemoryRegion::reflect("/tmp/unicode_text.txt");
    if (MemoryRegion *region = file.query()) {
        const char32_t *p = (const char32_t *)region->pointer(12 /* bytes */);
        region.toggleNetworkAndNative();
        String s = StringLiteral(Endianness::Native, p, 1024, true);
        printf("%S, size: %d, %x, %b", *s, region->bytes(), region->bytes(), region->bytes());
    } 

To create a vector, write:

    Vector<int> v = { 3, 2, 1 };
    int second = v[1];
    
Additional examples are available in the `UnitTests` directory.

## References

[1] www.arm.com
[2] www.microchip.com
[3] www.intel.com
