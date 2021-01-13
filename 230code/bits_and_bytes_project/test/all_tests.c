#include <gtest/gtest.h>
#include "../src/bits_and_bytes.h"

using namespace std;

class ProjectTests : public ::testing::Test
{
  protected:
    ProjectTests() {}          //constructor runs before each test
    virtual ~ProjectTests() {} //destructor cleans up after tests
    virtual void SetUp() {}    //sets up before each test (after constructor)
    virtual void TearDown() {} //clean up after each test, (before destructor)
};

#define MAX_LEN 1024

TEST(ProjectTests, Test1)
{
    char buffer[MAX_LEN + 1] = {0};
    int out_pipe[2];
    int saved_stdout;

    saved_stdout = dup(STDOUT_FILENO); /* save stdout for display later */

    if (pipe(out_pipe) != 0)
    { /* make a pipe */
        exit(1);
    }

    dup2(out_pipe[1], STDOUT_FILENO); /* redirect stdout to the pipe */
    close(out_pipe[1]);

    print_it();
    fflush(stdout);

    read(out_pipe[0], buffer, MAX_LEN);
    dup2(saved_stdout, STDOUT_FILENO);

    char v[] = "Bit operations are fun!\n";
    int c = strncmp(buffer, v, strlen(v));

    EXPECT_EQ(c, 0) << "Your print_it() function is not returning the EXACT string";
}


