//
//  UQLTests.cpp
//  Helixstore/Turbine/UQL Unit Tests
//

#include <Helixstore/ComputationalIndex.h>
// #include <Additions/Security.h>

String initial = StringLiteral(
R"(
    2012-01-01 12:00:00 !
        VAR passive = Sum([Sg_1]⸺[Sg_2]>⸺<v0>{A1920}, LastMonth) + 1.00
        VAR amount = Normal(102.00, 10.00), passive
        [Sg_1]⸺[Sg_2]>⸺<v1>{A1920} ↑ amount
        ⸺<<2⸺<v2>{A1920} ↑ Swap(amount) // Permutes a double-stranded value
    2012-01-01 13:00:00 ! [Sg_1]⸺[Sg_2]>⸺<v3>{A1920} ↑ 32.32, 200.32 ⬷ '9bb5ce27-2f74-49c6-bcc3-e1e59c6a83e5'
    2012-01-01 13:00:00 ! [Sg_1]⸺[Sg_2]>⸺<v3>{A1920} ↓ 32.32, 200.32 // Equivalent to ↑ -32.32, -200.32
    // prompt> PRINT SampleAfter('9bb5ce27-2f74-49c6-bcc3-e1e59c6a83e5')
    // prompt> PRINT SampleBefore('9bb5ce27-2f74-49c6-bcc3-e1e59c6a83e5')
    // prompt> PRINT SampleBefore(2012-01-01 13:00:00)
    // prompt> PEEK
    // prompt> COMMIT NOW
)");

String update = StringLiteral(
R"(
    2012-01-01 12:00:00 @ '9bb5ce27-2f74-49c6-bcc3-e1e59c6a83e5' = 33.32 + 1.00, 200.33
)");

String query = StringLiteral(
R"(
    2012-01-01 12:00:00 ? 0.3 * [Sg_1]--[sg_2]>--<v1>.Sum(A1920, LastMonth) + 1.00, 2.00
    2012-02-01 12:00:00 ? 0.3 * <<1>--<v3>.Sum(A1920, LastMonth) + 1.00
)");

struct MyDelegate : public ComputationalIndexDelegate {
    
    // CipherContext cipherContext;
    
    void progress(ComputationalIndex *index, String json) {
        Termlog << json << sep;
    }
    void subscription(ComputationalIndex *index, String json) {
        Termlog << "SUBSCRIPTION: " << json << sep;
    }
    int passphrase(ComputationalIndex *index, String fingerprint, void (^completion)(octa hash)) {
        
        __block int result = 0;
        
        if (Termlog.password(20, 5,
          ^(bool &stop) { result = -1; },
          ^(DecoratedString ds) {
              octa hash;
              completion(hash);
          }
        )) { result = -2; }
        
        return result;
    }
    int encrypt(ComputationalIndex *index, String plaintext, void (^completion)(String ciphertext)) {
        //Security::encryptString(plaintext, true, &cipherContext,
        //^(String &block) { completion(block); });
        completion(plaintext);
        return 0;
    }
    int decrypt(ComputationalIndex *index, String ciphertext, void (^completion)(String plaintext)) {
        //Security::decryptString(plaintext, true, &cipherContext,
        //^(String &block) { completion(block); });
        completion(ciphertext);
        return 0;
    }
    void appendToJournal(ComputationalIndex *index, String snippet) {
        Termlog << "JOURNAL: " << snippet << sep;
    }
    void addDevice(ComputationalIndex *index, String name, String address) {
        Termlog << "DEVICE: " << name << " on " << address << sep;
    }
    int resolveServer(ComputationalIndex *index, String servername, void (^completion)(String ip)) {
        String ip = StringLiteral("192.128.2.1");
        completion(ip);
        return 0;
    }
    void network(ComputationalIndex *index, String augment) {
        Termlog << "NETWORK : " << augment << sep;
    }
};

UNITTEST(UQL_1)
{
    MyDelegate delegate;
    ComputationalIndex complex("test", &delegate);
    
    complex.evaluate("foo.uql", initial);
    complex.evaluate("foo.uql", update);
    complex.evaluate("foo.uql", query);
}
