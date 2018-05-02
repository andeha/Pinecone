//
//  ComputationalIndexTests.cpp
//  Helixstore Unit Tests
//

#include <PineconeNucleus.h>
#include <Helixstore/ComputationalIndex.h>

INNER_FUNCTION
const char32_t *
ComputationalIndexOperationName(
    ComputationalIndex::Operation op
)
{
    switch (op) {
        case ComputationalIndex::Operation::addSubgraph:
            return U"addSugraph";
        case ComputationalIndex::Operation::removeSubgraph:
            return U"removeSubgraph";
        case ComputationalIndex::Operation::addVertex:
            return U"addVertex";
        case ComputationalIndex::Operation::removeVertex:
            return U"removeVertex";
        case ComputationalIndex::Operation::bridge:
            return U"bridge";
        case ComputationalIndex::Operation::unbridge:
            return U"unbridge";
        case ComputationalIndex::Operation::createkey:
            return U"createkey";
        case ComputationalIndex::Operation::delta:
            return U"delta";
        case ComputationalIndex::Operation::update:
            return U"update";
        case ComputationalIndex::Operation::include:
            return U"include";
        default: return U"unknown";
    }
}

UNITTEST(ComputationalIndex_1)
{
    ComputationalIndex complex("ComputationalIndex Case 1", NULL);
    auto machineString = Tuple<__builtin_int_t, char32_t *>(11, (char32_t *)U"mySubgraph1");
    Fossilate arg1; arg1.value.machineString = machineString; arg1.kind = 0;
    ComputationalIndex::Arguments args = { arg1 };
    complex.interpret(ComputationalIndex::Operation::addSubgraph, args);
    complex.peek(^(ComputationalIndex::Operation op,
      ComputationalIndex::Arguments e, bool& stop) {
        Termlog << ComputationalIndexOperationName(op) << eol;
    });
    String datetime = StringLiteral("2018-05-01 09:27:31");
    Chronology chronology = SystemInfoCalendricChronology();
    Optional<Chronology::Timestamp> ts = TS(chronology, datetime);
    if (Chronology::Timestamp *instant = ts.query()) {
        complex.commit(*instant);
    }
}
