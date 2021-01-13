#include <gtest/gtest.h>
#include <cstring>
#include "../src/count-strings.h"

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

void init(int n, Entry entries[]) {
  for (int i = 0; i < n; ++i) {
    entries[i].string = "";
    entries[i].count  = -1;
  }  
}

int find(int n, Entry entries[], char* key) {
    for (int i = 0; i < n; ++i) {
        if (strcmp(entries[i].string, key) == 0) {
            return entries[i].count;
        }
    }

    return -1;
}

TEST(ProjectTests, Test1)
{
    Entry entries[MAX_STRINGS];
    char *strings[] = {"abc"};
    int n = 1;

    init(n, entries);
    
    FILE* input_file = fopen("/dev/null", "r");
    ASSERT_TRUE(input_file != NULL) << "There was a problem opening the file '/dev/null'. Are you running tese tests on a Unix system?";    

    prepare_table(n, strings, entries);
    ASSERT_TRUE(entries[0].count != -1) << "Your prepare_table() function is not preparing the entry table correctly.";
    ASSERT_TRUE(strcmp(entries[0].string, "abc") == 0)
      << "Your prepare_table() function is not preparing the entry table correctly. You should take a look at how you set Entry.string.";    
    
    count_occurrences(n, input_file, entries);
    int freqabc = find(n, entries, "abc");

    EXPECT_EQ(freqabc, 0) << "Your count_occurences() function is not returning the correct value.";
}


