#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <gtest/gtest.h>
#include "../src/hw.h"

using namespace std;

class ProjectTests : public ::testing::Test
{
  protected:
    ProjectTests() {}          //constructor runs before each test
    virtual ~ProjectTests() {} //destructor cleans up after tests
    virtual void SetUp() {}    //sets up before each test (after constructor)
    virtual void TearDown() {} //clean up after each test, (before destructor)
};

#define MAX_WORD_SIZE 46

// We need to define the structs we define in wset.h so that the
// compiler is happy. We know what these structs are so we can
// simply give them a definition here and smiles all around.
typedef struct WordNode WordNode;
struct WordNode {
  int       freq;   // The frequency of the the word.
  char*     word;   // The word itself.
  WordNode* next;   // The next word node in the list.
};

struct WordSet {
  int       size;   // The number of elements in the set.
  WordNode* head;   // The starting node in the set.
};

/*****************************************************************************/
/* Words Unit Tests                                                          */
/*****************************************************************************/

TEST(ProjectTests, test_words_next_word)
{
    char  *word = NULL;

	FILE *file = fopen("test/test.txt", "r");
	ASSERT_TRUE(file != NULL) << "could not open file 'test/test.txt'";

	// Test word 1:
	word = words_next_word(file);
	EXPECT_STRNE(word, NULL) << "words_next_word() is returning NULL!";
	EXPECT_STREQ("this", word) << "words_next_word() returns incorrect string";
	EXPECT_EQ(strlen(word), 4) << "words_next_word() returns string of incorrect length";
	// Test word 2:
	word = words_next_word(file);
	EXPECT_STRNE(word, NULL) << "words_next_word() is returning NULL!";
	EXPECT_STREQ("is", word) << "words_next_word() returns incorrect string";
	EXPECT_EQ(strlen(word), 2) << "words_next_word() returns string of incorrect length";
	// Test word 3:
	word = words_next_word(file);
	EXPECT_STRNE(word, NULL) << "words_next_word() is returning NULL!";
	EXPECT_STREQ("some", word) << "words_next_word() returns incorrect string";
	EXPECT_EQ(strlen(word), 4) << "words_next_word() returns string of incorrect length";
	// Test word 4:
	word = words_next_word(file);
	EXPECT_STRNE(word, NULL) << "words_next_word() is returning NULL!";
	EXPECT_STREQ("text12", word) << "words_next_word() returns incorrect string";
	EXPECT_EQ(strlen(word), 6) << "words_next_word() returns string of incorrect length";
	// Test word 5:
	word = words_next_word(file);
	EXPECT_STRNE(word, NULL) << "words_next_word() is returning NULL!";
	EXPECT_STREQ("EXCELLENT", word) << "words_next_word() returns incorrect string";
	EXPECT_EQ(strlen(word), 9) << "words_next_word() returns string of incorrect length";

	fclose(file);
}

/*****************************************************************************/
/* WSet Unit Tests                                                           */
/*****************************************************************************/

TEST(ProjectTests, test_wset_new)
{
	WordSet* wset = wset_new();
	ASSERT_NE(wset, (WordSet*) NULL) << "The wset_new function is returning NULL!";
}

TEST(ProjectTests, test_wset_free)
{
	WordSet* wset = wset_new();
	ASSERT_NE(wset, (WordSet*) NULL) << "The wset_new function is returning NULL!";
	wset_free(wset);
}


