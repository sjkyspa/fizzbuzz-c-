#include <student.hpp>
#include <game.hpp>
#include <gtest/gtest.h>
#include <memory>

TEST(StudentTest, should_countoff_same_as_position_when_rule_is_empty) {
    std::vector<std::unique_ptr<student>> students;
    for (auto i = 0; i < 100; i++) {
        students.push_back(std::make_unique<student>(i + 1));
    }
    const std::shared_ptr<game> &ga = std::make_shared<game>(game());
    ga->involve(students);

    for (auto it = ga->students().begin(); it < ga->students().end(); it++) {
        std::unique_ptr<student> &ptr = *it;
        EXPECT_EQ(std::to_string(ptr->position()), ptr->countoff());
    }
}