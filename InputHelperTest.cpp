#include <gtest/gtest.h>
#include <string>
#include "InputHelper.h"
#include "Pawn.h"
#include "Knight.h"
#include "King.h"

using namespace std;

TEST(InputHelper, ShouldReturnEncodedChessboardSetup) {
    InputHelper inputHelper = InputHelper();
    vector<string> piecesWthPosition = inputHelper.readFile("../Board1.txt");

    EXPECT_EQ(piecesWthPosition[0], "sa1");
    EXPECT_EQ(piecesWthPosition[1], "bc2");
    EXPECT_EQ(piecesWthPosition[2], "bd4");
    EXPECT_EQ(piecesWthPosition[3], "be6");
    EXPECT_EQ(piecesWthPosition[4], "Kh8");
}

TEST(InputHelper, ShouldCreatedPiecesAccordingToPieceCode) {
    InputHelper inputHelper = InputHelper();
    vector<string> piecesWthPosition = {"sa1", "bc2", "bd4", "be6", "Kh8"};
    vector<Piece *> pieces = inputHelper.decodePieces(piecesWthPosition);
    bool castResult;
    if (dynamic_cast<Knight *>(pieces[0])) {
        castResult = true;
    } else {
        castResult = false;
    }
    if (dynamic_cast<Pawn *>(pieces[1])) {
        castResult = true;
    } else {
        castResult = false;
    }
    if (dynamic_cast<King *>(pieces[4])) {
        castResult = true;
    } else {
        castResult = false;
    }
    EXPECT_EQ(castResult, true);
}


TEST(InputHelper, ShouldReturnCorrectDecodedField00) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sa1")->toString(), (new Field(0, 0))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField01) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sa2")->toString(), (new Field(1, 0))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField02) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sa3")->toString(), (new Field(2, 0))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField03) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sa4")->toString(), (new Field(3, 0))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField04) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sa5")->toString(), (new Field(4, 0))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField05) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sa6")->toString(), (new Field(5, 0))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField06) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sa7")->toString(), (new Field(6, 0))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField07) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sa8")->toString(), (new Field(7, 0))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField10) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sb1")->toString(), (new Field(0, 1))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField11) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sb2")->toString(), (new Field(1, 1))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField12) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sb3")->toString(), (new Field(2, 1))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField13) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sb4")->toString(), (new Field(3, 1))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField14) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sb5")->toString(), (new Field(4, 1))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField15) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sb6")->toString(), (new Field(5, 1))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField16) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sb7")->toString(), (new Field(6, 1))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField17) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sb8")->toString(), (new Field(7, 1))->toString());
}

TEST(InputHelper, ShouldReturnCorrectDecodedField20) {
    InputHelper inputHelper;
    EXPECT_EQ(inputHelper.decodeField("sc1")->toString(), (new Field(0, 2))->toString());
}
