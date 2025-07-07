import std;

using namespace std;

void handleStackTrace(const stacktrace& trace)
{
    println("   Stack trace information:");
    println("      There are {} frames in the stack trace.", trace.size());
    println("   Here are all the frames in the stack trace:");
    println("----------------------------------------------------------------------------------------");
    println("{}", trace);
    for (size_t i = 0; i < trace.size(); ++i)
    {
        println("   Frame {}: {}", i, trace[i].description());
    }
    println("----------------------------------------------------------------------------------------");

}

void C()
{
    println("Entered C().");
    handleStackTrace(stacktrace::current());
    println("Exiting C().");
}

void B() {
    println("Entered B().");
    C();
    println("Exiting B().");
}

void A()
{
    println("Entered A().");
    B();
    println("Exiting A().");
}

int main()
{
    A();
}