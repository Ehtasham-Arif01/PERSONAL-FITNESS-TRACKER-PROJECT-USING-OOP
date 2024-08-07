#include <iostream>
#include <string>

using namespace std;

// Define constants
const int MAX_USERS = 100;
const int MAX_PREMIUM_USERS = 50;
const int MAX_WORKOUTS = 100;
const int MAX_GOAL_RECORDS = 100;
const int MAX_PROGRESS_RECORDS = 100;
const int MAX_NUTRITION_RECORDS = 100;
const int MAX_INSIGHT_RECORDS = 100;
const int MAX_SOCIAL_RECORDS = 100;

// Base User Class Definition
class User {
protected:
    int user_id;
    string name;
    int age;
    double weight; // in kg
    double height; // in cm
    string gender;
    string fitness_level;
    string goals;

public:
    // Default Constructor
    User() : user_id(0), age(0), weight(0), height(0) {}

    // Parameterized Constructor
    User(int id, string name, int age, double weight, double height, string gender, string fitness_level, string goals)
        : user_id(id), name(name), age(age), weight(weight), height(height), gender(gender), fitness_level(fitness_level), goals(goals) {}

    // Getter and Setter methods
    int getUserId() const { return user_id; }
    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    int getAge() const { return age; }
    void setAge(int age) { this->age = age; }

    double getWeight() const { return weight; }
    void setWeight(double weight) { this->weight = weight; }

    double getHeight() const { return height; }
    void setHeight(double height) { this->height = height; }

    string getGender() const { return gender; }
    void setGender(const string& gender) { this->gender = gender; }

    string getFitnessLevel() const { return fitness_level; }
    void setFitnessLevel(const string& fitness_level) { this->fitness_level = fitness_level; }

    string getGoals() const { return goals; }
    void setGoals(const string& goals) { this->goals = goals; }

    // Functions
    void registerUser(User users[], int& user_count, const User& user) {
        if (user_count < MAX_USERS) {
            users[user_count++] = user;
            cout << "\n\n*** USER REGISTERED SUCCESSFULLY! ***\n\n";
        } else {
            cout << "\n\n*** USER LIMIT REACHED. CANNOT REGISTER MORE USERS.***\n\n";
        }
    }

    void removeUser(User users[], int& user_count, int id) {
        bool found = false;
        for (int i = 0; i < user_count; ++i) {
            if (users[i].getUserId() == id) {
                for (int j = i; j < user_count - 1; ++j) {
                    users[j] = users[j + 1];
                }
                --user_count;
                found = true;
                cout << "\t\n\n***USER REMOVED SUCCESSFULLY!***\n\n";
                break;
            }
        }
        if (!found) {
            cout << "\n\n\t*** USER NOT FOUND ***\n\n";
        }
    }

    void searchUser(const User users[], int user_count, int id) const {
        bool found = false;
        for (int i = 0; i < user_count; ++i) {
            if (users[i].getUserId() == id) {
                users[i].viewProgress();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\n\n\t*** USER NOT FOUND ***\n\n";
        }
    }

    void updateUser(User users[], int user_count, int id, string new_name, int new_age, double new_weight, double new_height, string new_gender, string new_fitness_level, string new_goals) {
        bool found = false;
        for (int i = 0; i < user_count; ++i) {
            if (users[i].getUserId() == id) {
                users[i].setName(new_name);
                users[i].setAge(new_age);
                users[i].setWeight(new_weight);
                users[i].setHeight(new_height);
                users[i].setGender(new_gender);
                users[i].setFitnessLevel(new_fitness_level);
                users[i].setGoals(new_goals);
                found = true;
                cout << "\n\n\t*** User updated successfully! ***\n\n";
                break;
            }
        }
        if (!found) {
            cout << "\n\n\t*** User not found. ***\n\n";
        }
    }

    void viewProgress() const {
        cout << "\n*** User Progress ***\n";
        cout << "Name : "<< name <<"\n";
        cout << "Age: " << age << "\n";
        cout << "Weight: " << weight << " kg\n";
        cout << "Height: " << height << " cm\n";
        cout << "Fitness Level: " << fitness_level << "\n";
        cout << "Goals: " << goals << "\n";
    }
};

// PremiumUser Class Definition
class PremiumUser : public User {
private:
    string membership_status;
    string exclusive_workouts;
    string personalized_insights;

public:
    // Default Constructor
    PremiumUser() : User(), membership_status("Standard"), exclusive_workouts("None"), personalized_insights("None") {}

    // Parameterized Constructor
    PremiumUser(int id, string name, int age, double weight, double height, string gender, string fitness_level, string goals, string membership_status, string exclusive_workouts, string personalized_insights)
        : User(id, name, age, weight, height, gender, fitness_level, goals), membership_status(membership_status), exclusive_workouts(exclusive_workouts), personalized_insights(personalized_insights) {}

    // Getter and Setter methods
    string getMembershipStatus() const { return membership_status; }
    void setMembershipStatus(const string& membership_status) { this->membership_status = membership_status; }

    string getExclusiveWorkouts() const { return exclusive_workouts; }
    void setExclusiveWorkouts(const string& exclusive_workouts) { this->exclusive_workouts = exclusive_workouts; }

    string getPersonalizedInsights() const { return personalized_insights; }
    void setPersonalizedInsights(const string& personalized_insights) { this->personalized_insights = personalized_insights; }

    // Functions
    void accessExclusiveWorkouts() const {
        cout << "\n*** Exclusive Workouts for " << name << " ***\n"
              << exclusive_workouts << "\n";
    }

    void receivePersonalizedInsights() const {
        cout << "\n*** Personalized Insights for " << name << " ***\n"
              << personalized_insights << "\n";
    }
};

// Workout Class Definition
class Workout {
private:
    int workout_id;
    string type;
    int duration; // in minutes
    double calories_burned;
    string date;
    int user_id;
    string intensity_level;

public:
    // Default Constructor
    Workout() : workout_id(0), duration(0), calories_burned(0.0), user_id(0) {}

    // Parameterized Constructor
    Workout(int id, string type, int duration, double calories_burned, string date, int user_id, string intensity_level)
        : workout_id(id), type(type), duration(duration), calories_burned(calories_burned), date(date), user_id(user_id), intensity_level(intensity_level) {}

    // Getter and Setter methods
    int getWorkoutId() const { return workout_id; }
    void setWorkoutId(int id) { workout_id = id; }

    string getType() const { return type; }
    void setType(const string& type) { this->type = type; }

    int getDuration() const { return duration; }
    void setDuration(int duration) { this->duration = duration; }

    double getCaloriesBurned() const { return calories_burned; }
    void setCaloriesBurned(double calories_burned) { this->calories_burned = calories_burned; }

    string getDate() const { return date; }
    void setDate(const string& date) { this->date = date; }

    int getUserId() const { return user_id; }
    void setUserId(int user_id) { this->user_id = user_id; }

    string getIntensityLevel() const { return intensity_level; }
    void setIntensityLevel(const string& intensity_level) { this->intensity_level = intensity_level; }

    // Functions
    void addWorkout(Workout workouts[], int& workout_count, const Workout& workout) {
        if (workout_count < MAX_WORKOUTS) {
            workouts[workout_count++] = workout;
            cout << "\n\n\t*** Workout added successfully! ***\n\n";
        } else {
            cout << "\n\n\t*** Workout limit reached. Cannot add more workouts. ***\n\n";
        }
    }

    void removeWorkout(Workout workouts[], int& workout_count, int id) {
        bool found = false;
        for (int i = 0; i < workout_count; ++i) {
            if (workouts[i].getWorkoutId() == id) {
                for (int j = i; j < workout_count - 1; ++j) {
                    workouts[j] = workouts[j + 1];
                }
                --workout_count;
                found = true;
                cout << "\n\n\t*** Workout removed successfully! ***\n\n";
                break;
            }
        }
        if (!found) {
            cout << "\n\n*** Workout not found. ***\n\n";
        }
    }

    void searchWorkout(const Workout workouts[], int workout_count, int id) const {
        bool found = false;
        for (int i = 0; i < workout_count; ++i) {
            if (workouts[i].getWorkoutId() == id) {
                cout << "\n\n*** Workout Details ***\n\n"
                     << "Type: " << workouts[i].getType() << "\n"
                     << "Duration: " << workouts[i].getDuration() << " minutes\n"
                     << "Calories Burned: " << workouts[i].getCaloriesBurned() << "\n"
                     << "Date: " << workouts[i].getDate() << "\n"
                     << "User ID: " << workouts[i].getUserId() << "\n"
                     << "Intensity Level: " << workouts[i].getIntensityLevel() << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\n\n*** Workout not found. ***\n\n";
        }
    }

    void updateWorkout(Workout workouts[], int workout_count, int id, string new_type, int new_duration, double new_calories_burned, string new_date, int new_user_id, string new_intensity_level) {
        bool found = false;
        for (int i = 0; i < workout_count; ++i) {
            if (workouts[i].getWorkoutId() == id) {
                workouts[i].setType(new_type);
                workouts[i].setDuration(new_duration);
                workouts[i].setCaloriesBurned(new_calories_burned);
                workouts[i].setDate(new_date);
                workouts[i].setUserId(new_user_id);
                workouts[i].setIntensityLevel(new_intensity_level);
                found = true;
                cout << "\n\n*** Workout updated successfully! ***\n\n";
                break;
            }
        }
        if (!found) {
            cout << "\n\n*** Workout not found. ***\n\n";
        }
    }

    void viewWorkouts(const Workout workouts[], int workout_count) const {
        cout << "\n\n*** All Workouts ***\n\n";
        for (int i = 0; i < workout_count; ++i) {
            cout << "Workout ID: " << workouts[i].getWorkoutId() << "\n"
                 << "Type: " << workouts[i].getType() << "\n"
                 << "Duration: " << workouts[i].getDuration() << " minutes\n"
                 << "Calories Burned: " << workouts[i].getCaloriesBurned() << "\n"
                 << "Date: " << workouts[i].getDate() << "\n"
                 << "User ID: " << workouts[i].getUserId() << "\n"
                 << "Intensity Level: " << workouts[i].getIntensityLevel() << "\n\n";
        }
    }

    void suggestWorkouts(const User users[], int user_count) const {
        cout << "\n\n*** Workout Suggestions Based on User Fitness Level ***\n\n";
        for (int i = 0; i < user_count; ++i) {
            cout << "User: " << users[i].getName() << "\n";
            if (users[i].getFitnessLevel() == "Beginner") {
                cout << "Suggested Workout: Light Cardio\n";
            } else if (users[i].getFitnessLevel() == "Intermediate") {
                cout << "Suggested Workout: Moderate Strength Training\n";
            } else if (users[i].getFitnessLevel() == "Advanced") {
                cout << "Suggested Workout: High-Intensity Interval Training\n";
            }
            cout << "\n\n";
        }
    }
};

// Function to display the user management submenu
void displayUserMenu() {
    cout << "\n\n||____________ USER MANAGEMENT ____________||\n\n";
    cout << "1. Register User\n";
    cout << "2. Remove User\n";
    cout << "3. Search User\n";
    cout << "4. Update User\n";
    cout << "5. View User Progress\n";
    cout << "6. Access Premium Features\n";
    cout << "0. Back to Main Menu\n";
    cout << "\nEnter your choice: ";
}

// Function to display the workout management submenu
void displayWorkoutMenu() {
    cout << "\n\n||____________ WORKOUT MANAGEMENT ____________||\n\n";
    cout << "1. Add Workout\n";
    cout << "2. Remove Workout\n";
    cout << "3. Search Workout\n";
    cout << "4. Update Workout\n";
    cout << "5. View Workouts\n";
    cout << "6. Suggest Workouts\n";
    cout << "0. Back to Main Menu\n";
    cout << "\nEnter your choice: ";
}

////////////////////////////////////////////////////////////////////////
// Define the Goal class
class Goal {
private:
    int goalID;
    int userID;
    string type; // e.g., weight loss, muscle gain, endurance
    double target;
    string startDate;
    string endDate;
    string status; // e.g., ongoing, completed
    double milestones[10]; // Intermediate targets to track goal achievement
    int milestoneCount;

public:
    // Constructor
    Goal(int gID = 0, int uID = 0, const string& t = "", double tgt = 0.0, const string& sDate = "", const string& eDate = "", const string& stat = "")
        : goalID(gID), userID(uID), type(t), target(tgt), startDate(sDate), endDate(eDate), status(stat), milestoneCount(0) {}

    // Method to set a new goal
    void setGoal() {
        cout << "\n\n--- Set New Goal ---\n\n";
        cout << "Enter Goal ID: ";
        while (!(cin >> goalID)) {
            cout << "Invalid input. Please enter a valid integer for Goal ID: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cout << "Enter User ID: ";
        while (!(cin >> userID)) {
            cout << "Invalid input. Please enter a valid integer for User ID: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cin.ignore();  // Ignore leftover newline
        cout << "Enter Goal Type (e.g., weight loss, muscle gain, endurance): ";
        getline(cin, type);

        cout << "Enter Target: ";
        while (!(cin >> target) || target < 0) {
            cout << "Invalid input. Please enter a non-negative number for Target: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cin.ignore(); // Ignore leftover newline
        cout << "Enter Start Date (YYYY-MM-DD): ";
        getline(cin, startDate);

        cout << "Enter End Date (YYYY-MM-DD): ";
        getline(cin, endDate);

        cout << "Enter Status (ongoing/completed): ";
        getline(cin, status);

        cout << "Enter number of milestones (max 10): ";
        while (!(cin >> milestoneCount) || milestoneCount < 0 || milestoneCount > 10) {
            cout << "Invalid input. Please enter a number between 0 and 10 for Milestones: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        for (int i = 0; i < milestoneCount; ++i) {
            cout << "Enter milestone " << (i + 1) << ": ";
            while (!(cin >> milestones[i]) || milestones[i] < 0) {
                cout << "Invalid input. Please enter a non-negative number for Milestone: ";
                cin.clear(); // Clear error flag
                cin.ignore(10000, '\n'); // Discard invalid input
            }
        }
    }

    // Method to update an existing goal
    void updateGoal() {
        cout << "\n--- Update Goal ---\n";
        setGoal(); // For simplicity, just reusing setGoal to update
    }

    // Method to view goal details
    void viewGoals() const {
        cout << "\n--- Goal Details ---\n"
             << "Goal ID: " << goalID << "\n"
             << "User ID: " << userID << "\n"
             << "Type: " << type << "\n"
             << "Target: " << target << "\n"
             << "Start Date: " << startDate << "\n"
             << "End Date: " << endDate << "\n"
             << "Status: " << status << "\n"
             << "Milestones: ";
        for (int i = 0; i < milestoneCount; ++i) {
            cout << milestones[i] << " ";
        }
        cout << "\n---------------------\n";
    }

    // Method to track goal progress
    void trackGoalProgress() const {
        cout << "\n\n--- Track Goal Progress ---\n\n";
        cout << "Current status for Goal ID " << goalID << ":\n";
        cout << "Target: " << target << "\n";
        cout << "Milestones achieved: ";
        // Example of tracking milestones (this can be expanded as needed)
        for (int i = 0; i < milestoneCount; ++i) {
            cout << milestones[i] << " ";
        }
        cout << "\n\n-----------------------------\n\n";
    }

    // Method to notify milestone achievement
    void notifyMilestoneAchievement(double achieved) const {
        cout << "\n\n--- Milestone Achievement Notification ---\n\n";
        bool milestoneAchieved = false;
        for (int i = 0; i < milestoneCount; ++i) {
            if (achieved >= milestones[i]) {
                cout << "Congratulations! You have achieved milestone " << milestones[i] << "!\n";
                milestoneAchieved = true;
            }
        }
        if (!milestoneAchieved) {
            cout << "No milestones achieved yet.\n";
        }
        cout << "\n----------------------------------------\n\n";
    }

    // Getter for goalID (for searching)
    int getGoalID() const {
        return goalID;
    }
};

// Global array to store goal records
Goal goalRecords[MAX_GOAL_RECORDS];
int goalCount = 0;

// Function prototypes
void setGoal();
void updateGoal();
void viewGoals();
void trackGoalProgress();
void notifyMilestoneAchievement();
void showMainMenu();
void showGoalManagementMenu();

// Function to set a new goal
void setGoal() {
    if (goalCount < MAX_GOAL_RECORDS) {
        Goal g;
        g.setGoal();
        goalRecords[goalCount++] = g;
        cout << "\nGoal successfully set.\n";
    } else {
        cout << "\n\nError: Maximum number of records reached. Cannot add more goals.\n\n";
    }
}

// Function to update an existing goal
void updateGoal() {
    int id;
    cout << "\n--- Update Existing Goal ---\n";
    cout << "Enter Goal ID to update: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid integer for Goal ID: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    for (int i = 0; i < goalCount; ++i) {
        if (goalRecords[i].getGoalID() == id) {
            goalRecords[i].updateGoal();
            cout << "Goal successfully updated.\n";
            return;
        }
    }
    cout << "\nError: Goal ID not found.\n";
}

// Function to view goal details
void viewGoals() {
    int id;
    cout << "\n--- View Goal Details ---\n";
    cout << "Enter Goal ID to view: ";
    while (!(cin >> id)) {
        cout << "\nInvalid input. Please enter a valid integer for Goal ID: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    for (int i = 0; i < goalCount; ++i) {
        if (goalRecords[i].getGoalID() == id) {
            goalRecords[i].viewGoals();
            return;
        }
    }
    cout << "\nError: Goal ID not found.\n";
}

// Function to track goal progress
void trackGoalProgress() {
    int id;
    cout << "\n--- Track Goal Progress ---\n";
    cout << "Enter Goal ID to track: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid integer for Goal ID: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    for (int i = 0; i < goalCount; ++i) {
        if (goalRecords[i].getGoalID() == id) {
            goalRecords[i].trackGoalProgress();
            return;
        }
    }
    cout << "\nError: Goal ID not found.\n";
}

// Function to notify milestone achievement
void notifyMilestoneAchievement() {
    int id;
    double achieved;
    cout << "\n\n--- Notify Milestone Achievement ---\n\n";
    cout << "Enter Goal ID to check milestones: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid integer for Goal ID: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    cout << "Enter achieved value to check against milestones: ";
    while (!(cin >> achieved) || achieved < 0) {
        cout << "\nInvalid input. Please enter a non-negative number for achieved value: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    for (int i = 0; i < goalCount; ++i) {
        if (goalRecords[i].getGoalID() == id) {
            goalRecords[i].notifyMilestoneAchievement(achieved);
            return;
        }
    }
    cout << "\nError: Goal ID not found.\n";
}

// Function to show the Goal Management menu
void showGoalManagementMenu() {
    int choice;
    do {
        cout << "\n\n||____________ GOAL MANAGMENT ____________||\n\n";
        cout << "1. Set New Goal\n";
        cout << "2. Update Existing Goal\n";
        cout << "3. View Goal Details\n";
        cout << "4. Track Goal Progress\n";
        cout << "5. Notify Milestone Achievement\n";
        cout << "6. Return to Main Menu\n";
        cout << "\nEnter your choice (1-6): ";
        while (!(cin >> choice) || choice < 1 || choice > 6) {
            cout << "\nInvalid choice. Please enter a number between 1 and 6: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        switch (choice) {
            case 1: setGoal(); break;
            case 2: updateGoal(); break;
            case 3: viewGoals(); break;
            case 4: trackGoalProgress(); break;
            case 5: notifyMilestoneAchievement(); break;
            case 6: cout << "\nReturning to Main Menu...\n"; break;
            default: cout << "\nInvalid choice, please try again.\n"; break;
        }
    } while (choice != 6);
}

///////////////////////////////////////////////////////////////////////////////////
// Define the Progress class
class Progress {
private:
    int progressID;
    int userID;
    string date;
    double weight;
    double bmi;
    double muscleMass;
    double fatPercentage;

public:
    // Constructor
    Progress(int pID = 0, int uID = 0, const string& d = "", double w = 0.0, double b = 0.0, double m = 0.0, double f = 0.0)
        : progressID(pID), userID(uID), date(d), weight(w), bmi(b), muscleMass(m), fatPercentage(f) {}

    // Method to log progress
    void logProgress() {
        cout << "\nEnter Progress ID: ";
        while (!(cin >> progressID)) {
            cout << "\nInvalid input. Please enter a valid integer for Progress ID: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cout << "Enter User ID: ";
        while (!(cin >> userID)) {
            cout << "\nInvalid input. Please enter a valid integer for User ID: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cin.ignore();  // Ignore leftover newline
        cout << "Enter Date (YYYY-MM-DD): ";
        getline(cin, date);

        cout << "Enter Weight (kg): ";
        while (!(cin >> weight) || weight < 0) {
            cout << "\nInvalid input. Please enter a non-negative number for Weight: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cout << "Enter BMI: ";
        while (!(cin >> bmi) || bmi < 0) {
            cout << "\nInvalid input. Please enter a non-negative number for BMI: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cout << "Enter Muscle Mass (kg): ";
        while (!(cin >> muscleMass) || muscleMass < 0) {
            cout << "\nInvalid input. Please enter a non-negative number for Muscle Mass: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cout << "Enter Fat Percentage (%): ";
        while (!(cin >> fatPercentage) || fatPercentage < 0) {
            cout << "\nInvalid input. Please enter a non-negative number for Fat Percentage: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }
    }

    // Method to update progress
    void updateProgress() {
        cout << "\nUpdating Progress...\n";
        logProgress(); // For simplicity, just reusing logProgress to update
    }

    // Method to view progress
    void viewProgress() const {
        cout << "\n--- Progress Details ---\n"
             << "Progress ID: " << progressID << "\n"
             << "User ID: " << userID << "\n"
             << "Date: " << date << "\n"
             << "Weight: " << weight << " kg\n"
             << "BMI: " << bmi << "\n"
             << "Muscle Mass: " << muscleMass << " kg\n"
             << "Fat Percentage: " << fatPercentage << "%\n"
             << "-------------------------\n";
    }

    // Method to generate a simple report
    void generateReport() const {
        cout << "\n--- Generating Report ---\n";
        viewProgress();
    }

    // Method to predict future progress (basic example)
    void predictFutureProgress() const {
        cout << "\n--- Predicting Future Progress ---\n";
        cout << "Based on current data:\n";
        cout << "Estimated future weight: " << weight + 1.0 << " kg\n";
        cout << "Estimated future BMI: " << bmi + 0.5 << "\n";
        cout << "Estimated future muscle mass: " << muscleMass + 0.5 << " kg\n";
        cout << "Estimated future fat percentage: " << fatPercentage - 0.5 << "%\n";
    }

    // Getter for progressID (for searching)
    int getProgressID() const {
        return progressID;
    }
};

// Global array to store progress records
Progress progressRecords[MAX_PROGRESS_RECORDS];
int recordCount = 0;

// Function prototypes
void addProgress();
void updateProgress();
void viewProgress();
void generateReport();
void predictFutureProgress();
void showMainMenu();
void showProgressManagementMenu();

// Function to add progress
void addProgress() {
    if (recordCount < MAX_PROGRESS_RECORDS) {
        Progress p;
        cout << "\n\n--- Log New Progress ---\n\n";
        p.logProgress();
        progressRecords[recordCount++] = p;
        cout << "Progress successfully logged.\n";
    } else {
        cout << "Error: Maximum number of records reached. Cannot add more progress.\n";
    }
}

// Function to update progress
void updateProgress() {
    int id;
    cout << "\n--- Update Existing Progress ---\n";
    cout << "Enter Progress ID to update: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid integer for Progress ID: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    for (int i = 0; i < recordCount; ++i) {
        if (progressRecords[i].getProgressID() == id) {
            progressRecords[i].updateProgress();
            cout << "Progress successfully updated.\n";
            return;
        }
    }
    cout << "Error: Progress ID not found.\n";
}

// Function to view progress
void viewProgress() {
    int id;
    cout << "\n\n--- View Progress Details ---\n\n";
    cout << "Enter Progress ID to view: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid integer for Progress ID: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    for (int i = 0; i < recordCount; ++i) {
        if (progressRecords[i].getProgressID() == id) {
            progressRecords[i].viewProgress();
            return;
        }
    }
    cout << "Error: Progress ID not found.\n";
}

// Function to generate a report for all records
void generateReport() {
    if (recordCount == 0) {
        cout << "No records available to generate a report.\n";
        return;
    }
    cout << "\n--- Generating Report for All Records ---\n";
    for (int i = 0; i < recordCount; ++i) {
        progressRecords[i].generateReport();
        cout << "------------------------\n";
    }
}

// Function to predict future progress for all records
void predictFutureProgress() {
    if (recordCount == 0) {
        cout << "No records available to predict future progress.\n";
        return;
    }
    cout << "\n--- Predicting Future Progress for All Records ---\n";
    for (int i = 0; i < recordCount; ++i) {
        progressRecords[i].predictFutureProgress();
        cout << "------------------------\n";
    }
}

// Function to show the Progress Management menu
void showProgressManagementMenu() {
    int choice;
    do {
        cout << "\n\n||____________ PROGRESS MANAGEMENT ____________||\n\n";
        cout << "1. Add New Progress Record\n";
        cout << "2. Update Existing Progress Record\n";
        cout << "3. View Progress Record\n";
        cout << "4. Generate Report for All Records\n";
        cout << "5. Predict Future Progress\n";
        cout << "6. Return to Main Menu\n";
        cout << "\nEnter your choice (1-6): ";
        while (!(cin >> choice) || choice < 1 || choice > 6) {
            cout << "Invalid choice. Please enter a number between 1 and 6: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        switch (choice) {
            case 1: addProgress(); break;
            case 2: updateProgress(); break;
            case 3: viewProgress(); break;
            case 4: generateReport(); break;
            case 5: predictFutureProgress(); break;
            case 6: cout << "Returning to Main Menu...\n"; break;
        }
    } while (choice != 6);
}

//////////////////////////////////////////////////////////////////////////////////////////
// Define the Nutrition class
class Nutrition {
private:
    int mealID;
    int userID;
    string date;
    string mealType;
    double calories;
    double carbs;
    double proteins;
    double fats;

public:
    // Constructor
    Nutrition(int mID = 0, int uID = 0, const string& d = "", const string& mt = "", double c = 0.0, double ca = 0.0, double p = 0.0, double f = 0.0)
        : mealID(mID), userID(uID), date(d), mealType(mt), calories(c), carbs(ca), proteins(p), fats(f) {}

    // Method to log a meal
    void logMeal() {
        cout << "\n\n--- Log Meal ---\n\n";
        cout << "Enter Meal ID: ";
        while (!(cin >> mealID)) {
            cout << "Invalid input. Please enter a valid integer for Meal ID: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cout << "Enter User ID: ";
        while (!(cin >> userID)) {
            cout << "Invalid input. Please enter a valid integer for User ID: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cin.ignore(); // Ignore leftover newline
        cout << "Enter Date (YYYY-MM-DD): ";
        getline(cin, date);

        cout << "Enter Meal Type (breakfast, lunch, dinner, snack): ";
        getline(cin, mealType);

        cout << "Enter Calories: ";
        while (!(cin >> calories)) {
            cout << "Invalid input. Please enter a valid number for Calories: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cout << "Enter Carbs (grams): ";
        while (!(cin >> carbs)) {
            cout << "Invalid input. Please enter a valid number for Carbs: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cout << "Enter Proteins (grams): ";
        while (!(cin >> proteins)) {
            cout << "Invalid input. Please enter a valid number for Proteins: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cout << "Enter Fats (grams): ";
        while (!(cin >> fats)) {
            cout << "Invalid input. Please enter a valid number for Fats: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cout << "Meal logged successfully.\n";
    }

    // Method to update a meal
    void updateMeal() {
        logMeal(); 
    }

    // Method to view meals
    void viewMeals() const {
        cout << "\n--- View Meal ---\n";
        cout << "Meal ID: " << mealID << "\n"
             << "User ID: " << userID << "\n"
             << "Date: " << date << "\n"
             << "Meal Type: " << mealType << "\n"
             << "Calories: " << calories << " kcal\n"
             << "Carbs: " << carbs << " grams\n"
             << "Proteins: " << proteins << " grams\n"
             << "Fats: " << fats << " grams\n";
    }

    // Method to calculate daily intake
    static void calculateDailyIntake(const Nutrition records[], int count) {
        double totalCalories = 0.0, totalCarbs = 0.0, totalProteins = 0.0, totalFats = 0.0;

        for (int i = 0; i < count; ++i) {
            totalCalories += records[i].calories;
            totalCarbs += records[i].carbs;
            totalProteins += records[i].proteins;
            totalFats += records[i].fats;
        }

        cout << "\n--- Daily Intake Summary ---\n";
        cout << "Total Calories: " << totalCalories << " kcal\n";
        cout << "Total Carbs: " << totalCarbs << " grams\n";
        cout << "Total Proteins: " << totalProteins << " grams\n";
        cout << "Total Fats: " << totalFats << " grams\n";
    }

    // Method to suggest meal plans
    static void suggestMealPlan() {
        cout << "\n--- Suggest Meal Plan ---\n";
        cout << "Suggested Meal Plan:\n";
        cout << "Breakfast: Oatmeal with fruits and nuts\n";
        cout << "Lunch: Grilled chicken with quinoa and vegetables\n";
        cout << "Dinner: Baked salmon with sweet potatoes and green salad\n";
        cout << "Snacks: Greek yogurt with honey and almonds\n";
    }

    // Getter for mealID (for searching)
    int getMealID() const {
        return mealID;
    }
};

// Global array to store nutrition records
Nutrition nutritionRecords[MAX_NUTRITION_RECORDS];
int nutritionCount = 0;

// Function prototypes
void logMeal();
void updateMeal();
void viewMeals();
void calculateDailyIntake();
void suggestMealPlan();
void showMainMenu();
void showNutritionManagementMenu();

// Function to log a meal
void logMeal() {
    if (nutritionCount < MAX_NUTRITION_RECORDS) {
        Nutrition n;
        n.logMeal();
        nutritionRecords[nutritionCount++] = n;
        cout << "Meal logged successfully.\n";
    } else {
        cout << "Error: Maximum number of records reached. Cannot add more meals.\n";
    }
}

// Function to update a meal
void updateMeal() {
    int id;
    cout << "\n--- Update Meal ---\n";
    cout << "Enter Meal ID to update: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid integer for Meal ID: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    for (int i = 0; i < nutritionCount; ++i) {
        if (nutritionRecords[i].getMealID() == id) {
            nutritionRecords[i].updateMeal();
            cout << "Meal updated successfully.\n";
            return;
        }
    }
    cout << "Error: Meal ID not found.\n";
}

// Function to view a meal
void viewMeals() {
    int id;
    cout << "\n--- View Meal ---\n";
    cout << "Enter Meal ID to view: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid integer for Meal ID: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    for (int i = 0; i < nutritionCount; ++i) {
        if (nutritionRecords[i].getMealID() == id) {
            nutritionRecords[i].viewMeals();
            return;
        }
    }
    cout << "Error: Meal ID not found.\n";
}

// Function to calculate daily intake
void calculateDailyIntake() {
    cout << "\n--- Calculate Daily Intake ---\n";
    Nutrition::calculateDailyIntake(nutritionRecords, nutritionCount);
}

// Function to suggest meal plans
void suggestMealPlan() {
    cout << "\n--- Suggest Meal Plan ---\n";
    Nutrition::suggestMealPlan();
}

// Function to show the Nutrition Management menu
void showNutritionManagementMenu() {
    int choice;
    do {
        cout << "\n--- ||____________ NUTRITION MANAGEMENT ____________||---\n";
        cout << "1. Log Meal\n";
        cout << "2. Update Meal\n";
        cout << "3. View Meals\n";
        cout << "4. Calculate Daily Intake\n";
        cout << "5. Suggest Meal Plan\n";
        cout << "6. Return to Main Menu\n";
        cout << "\nEnter your choice (1-6): ";
        while (!(cin >> choice) || choice < 1 || choice > 6) {
            cout << "Invalid choice. Please enter a number between 1 and 6: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        switch (choice) {
            case 1: logMeal(); break;
            case 2: updateMeal(); break;
            case 3: viewMeals(); break;
            case 4: calculateDailyIntake(); break;
            case 5: suggestMealPlan(); break;
            case 6: cout << "Returning to Main Menu...\n"; break;
            default: cout << "Invalid choice, please try again.\n"; break;
        }
    } while (choice != 6);
}

/////////////////////////////////////////////////////////////////////////////
// Define the Insights class
class Insights {
private:
    int insightID;
    int userID;
    string date;
    string summary;
    string recommendations;

public:
    // Constructor
    Insights(int iID = 0, int uID = 0, const string& d = "", const string& s = "", const string& r = "")
        : insightID(iID), userID(uID), date(d), summary(s), recommendations(r) {}

    // Method to generate daily insight
    void generateDailyInsight() {
        cout << "\n--- Generate Daily Insight ---\n";
        cout << "Enter Insight ID: ";
        while (!(cin >> insightID)) {
            cout << "Invalid input. Please enter a valid integer for Insight ID: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cout << "Enter User ID: ";
        while (!(cin >> userID)) {
            cout << "Invalid input. Please enter a valid integer for User ID: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cin.ignore(); // Ignore leftover newline
        cout << "Enter Date (YYYY-MM-DD): ";
        getline(cin, date);

        cout << "Enter Summary: ";
        getline(cin, summary);

        cout << "Enter Recommendations: ";
        getline(cin, recommendations);

        cout << "Daily Insight generated successfully.\n";
    }

    // Method to generate weekly insight
    void generateWeeklyInsight() {
        cout << "\n--- Generate Weekly Insight ---\n";
        generateDailyInsight(); // For simplicity, reuse daily insight generation
    }

    // Method to generate monthly insight
    void generateMonthlyInsight() {
        cout << "\n--- Generate Monthly Insight ---\n";
        generateDailyInsight(); // For simplicity, reuse daily insight generation
    }

    // Method to provide recommendations based on the insights
    void provideRecommendations() const {
        cout << "\n--- Provide Recommendations ---\n";
        cout << "Recommendations: " << recommendations << "\n";
    }

    // Method to analyze workout patterns
    void analyzeWorkoutPatterns() const {
        cout << "\n--- Analyze Workout Patterns ---\n";
        // Example analysis (expand as needed)
        cout << "Analyzing workout patterns for Insight ID " << insightID << "...\n";
        cout << "Summary: " << summary << "\n";
        cout << "Recommendations: " << recommendations << "\n";
    }

    // Getter for insightID (for searching)
    int getInsightID() const {
        return insightID;
    }
};

// Global array to store insight records
Insights insightRecords[MAX_INSIGHT_RECORDS];
int insightCount = 0;

// Function prototypes
void generateDailyInsight();
void generateWeeklyInsight();
void generateMonthlyInsight();
void provideRecommendations();
void analyzeWorkoutPatterns();
void showMainMenu();
void showInsightsManagementMenu();

// Function to generate a daily insight
void generateDailyInsight() {
    if (insightCount < MAX_INSIGHT_RECORDS) {
        Insights i;
        i.generateDailyInsight();
        insightRecords[insightCount++] = i;
        cout << "Daily Insight logged successfully.\n";
    } else {
        cout << "Error: Maximum number of records reached. Cannot add more insights.\n";
    }
}

// Function to generate a weekly insight
void generateWeeklyInsight() {
    cout << "\n--- Generate Weekly Insight ---\n";
    if (insightCount > 0) {
        insightRecords[insightCount - 1].generateWeeklyInsight(); // Just an example using the last record
    } else {
        cout << "Error: No insights available to generate weekly insight.\n";
    }
}

// Function to generate a monthly insight
void generateMonthlyInsight() {
    cout << "\n--- Generate Monthly Insight ---\n";
    if (insightCount > 0) {
        insightRecords[insightCount - 1].generateMonthlyInsight(); // Just an example using the last record
    } else {
        cout << "Error: No insights available to generate monthly insight.\n";
    }
}

// Function to provide recommendations
void provideRecommendations() {
    int id;
    cout << "\n--- Provide Recommendations ---\n";
    cout << "Enter Insight ID to provide recommendations: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid integer for Insight ID: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    for (int i = 0; i < insightCount; ++i) {
        if (insightRecords[i].getInsightID() == id) {
            insightRecords[i].provideRecommendations();
            return;
        }
    }
    cout << "Error: Insight ID not found.\n";
}

// Function to analyze workout patterns
void analyzeWorkoutPatterns() {
    int id;
    cout << "\n--- Analyze Workout Patterns ---\n";
    cout << "Enter Insight ID to analyze patterns: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid integer for Insight ID: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    for (int i = 0; i < insightCount; ++i) {
        if (insightRecords[i].getInsightID() == id) {
            insightRecords[i].analyzeWorkoutPatterns();
            return;
        }
    }
    cout << "Error: Insight ID not found.\n";
}

// Function to show the Insights Management menu
void showInsightsManagementMenu() {
    int choice;
    do {
        cout << "\n||____________ INSIGHT MANAGEMENT  ____________||\n";
        cout << "1. Generate Daily Insight\n";
        cout << "2. Generate Weekly Insight\n";
        cout << "3. Generate Monthly Insight\n";
        cout << "4. Provide Recommendations\n";
        cout << "5. Analyze Workout Patterns\n";
        cout << "6. Return to Main Menu\n";
        cout << "Enter your choice (1-6): ";
        while (!(cin >> choice) || choice < 1 || choice > 6) {
            cout << "Invalid choice. Please enter a number between 1 and 6: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        switch (choice) {
            case 1: generateDailyInsight(); break;
            case 2: generateWeeklyInsight(); break;
            case 3: generateMonthlyInsight(); break;
            case 4: provideRecommendations(); break;
            case 5: analyzeWorkoutPatterns(); break;
            case 6: cout << "Returning to Main Menu...\n"; break;
            default: cout << "Invalid choice, please try again.\n"; break;
        }
    } while (choice != 6);
}

//////////////////////////////////////////////////////////
// Define the Social class
class Social {
private:
    int postID;
    int userID;
    string date;
    string content;
    int likes;
    string comments; // Comments will be a single string for simplicity

public:
    // Constructor
    Social(int pID = 0, int uID = 0, const string& d = "", const string& c = "", int l = 0, const string& cm = "")
        : postID(pID), userID(uID), date(d), content(c), likes(l), comments(cm) {}

    // Method to create a post
    void createPost() {
        cout << "\n--- Create Post ---\n";
        cout << "Enter Post ID: ";
        while (!(cin >> postID)) {
            cout << "Invalid input. Please enter a valid integer for Post ID: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cout << "Enter User ID: ";
        while (!(cin >> userID)) {
            cout << "Invalid input. Please enter a valid integer for User ID: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        cin.ignore(); // Ignore leftover newline
        cout << "Enter Date (YYYY-MM-DD): ";
        getline(cin, date);

        cout << "Enter Post Content: ";
        getline(cin, content);

        likes = 0; // Initialize likes to 0
        comments = ""; // Initialize comments to empty string

        cout << "Post created successfully.\n";
    }

    // Method to delete a post
    void deletePost() {
        cout << "\n--- Delete Post ---\n";
        cout << "Post ID: " << postID << " has been deleted.\n";
        // In a real application, you would remove this post from storage
    }

    // Method to like a post
    void likePost() {
        ++likes;
        cout << "Post liked successfully. Total likes: " << likes << endl;
    }

    // Method to comment on a post
    void commentOnPost() {
        string comment;
        cout << "Enter your comment: ";
        cin.ignore(); // Ignore leftover newline
        getline(cin, comment);
        comments += (comments.empty() ? "" : "\n") + comment; // Append new comment
        cout << "Comment added successfully.\n";
    }

    // Method to view posts
    void viewPosts() const {
        cout << "\n--- View Post ---\n";
        cout << "Post ID: " << postID << "\n"
             << "User ID: " << userID << "\n"
             << "Date: " << date << "\n"
             << "Content: " << content << "\n"
             << "Likes: " << likes << "\n"
             << "Comments:\n" << comments << "\n";
    }

    // Getter for postID (for searching)
    int getPostID() const {
        return postID;
    }
};

// Global array to store social posts
Social socialPosts[MAX_SOCIAL_RECORDS];
int socialCount = 0;

// Function prototypes
void createPost();
void deletePost();
void likePost();
void commentOnPost();
void viewPosts();
void showMainMenu();
void showSocialManagementMenu();

// Function to create a post
void createPost() {
    if (socialCount < MAX_SOCIAL_RECORDS) {
        Social s;
        s.createPost();
        socialPosts[socialCount++] = s;
        cout << "Post created successfully.\n";
    } else {
        cout << "Error: Maximum number of posts reached. Cannot create more posts.\n";
    }
}

// Function to delete a post
void deletePost() {
    int id;
    cout << "\n--- Delete Post ---\n";
    cout << "Enter Post ID to delete: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid integer for Post ID: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    for (int i = 0; i < socialCount; ++i) {
        if (socialPosts[i].getPostID() == id) {
            socialPosts[i].deletePost();
            // In a real application, you would remove this post from storage
            // For simplicity, just shift remaining records
            for (int j = i; j < socialCount - 1; ++j) {
                socialPosts[j] = socialPosts[j + 1];
            }
            --socialCount;
            cout << "Post deleted successfully.\n";
            return;
        }
    }
    cout << "Error: Post ID not found.\n";
}

// Function to like a post
void likePost() {
    int id;
    cout << "\n--- Like Post ---\n";
    cout << "Enter Post ID to like: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid integer for Post ID: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    for (int i = 0; i < socialCount; ++i) {
        if (socialPosts[i].getPostID() == id) {
            socialPosts[i].likePost();
            return;
        }
    }
    cout << "Error: Post ID not found.\n";
}

// Function to comment on a post
void commentOnPost() {
    int id;
    cout << "\n--- Comment on Post ---\n";
    cout << "Enter Post ID to comment on: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid integer for Post ID: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    for (int i = 0; i < socialCount; ++i) {
        if (socialPosts[i].getPostID() == id) {
            socialPosts[i].commentOnPost();
            return;
        }
    }
    cout << "Error: Post ID not found.\n";
}

// Function to view posts
void viewPosts() {
    int id;
    cout << "\n--- View Post ---\n";
    cout << "Enter Post ID to view: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Please enter a valid integer for Post ID: ";
        cin.clear(); // Clear error flag
        cin.ignore(10000, '\n'); // Discard invalid input
    }

    for (int i = 0; i < socialCount; ++i) {
        if (socialPosts[i].getPostID() == id) {
            socialPosts[i].viewPosts();
            return;
        }
    }
    cout << "Error: Post ID not found.\n";
}

// Function to show the Social Management menu
void showSocialManagementMenu() {
    int choice;
    do {
        cout << "\n||____________ SOCIAL MANAGEMENT ____________||\n";
        cout << "1. Create Post\n";
        cout << "2. Delete Post\n";
        cout << "3. Like Post\n";
        cout << "4. Comment on Post\n";
        cout << "5. View Posts\n";
        cout << "6. Return to Main Menu\n";
        cout << "Enter your choice (1-6): ";
        while (!(cin >> choice) || choice < 1 || choice > 6) {
            cout << "Invalid choice. Please enter a number between 1 and 6: ";
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }

        switch (choice) {
            case 1: createPost(); break;
            case 2: deletePost(); break;
            case 3: likePost(); break;
            case 4: commentOnPost(); break;
            case 5: viewPosts(); break;
            case 6: cout << "Returning to Main Menu...\n"; break;
            default: cout << "Invalid choice, please try again.\n"; break;
        }
    } while (choice != 6);
}
//////////////////////////////////////////////////////////
void displayWelcomeMessage() {

    // Display the welcome message
    cout << "\n\n\n\n\t\t\t\t||================================================||\n\n";
    cout << "\t\t\t\t         PERSONAL FITNESS TRACKER APPLICATION\n\n";
    cout << "\t\t\t\t||================================================||\n\n";
    cout << "\t\t\t\t         WELCOME TO PERSONAL FITNESS TRACKER !\n\n";
    cout << "\t\t\t\t||================================================||\n\n\n";

    cout<<"\n\t\t____DEVELOPED BY : ANONYMOUS *** \n";
   
    cout << "\n\nPress Enter to continue...";
}
// Function to display the main menu
void displayMainMenu() {
    cout << "\n\n\t\t||____________ MAIN MENU ____________||\n\n";
    cout << "\t\t1) USER MANAGEMENT\n";
    cout << "\t\t2) WORKOUT MANAGEMENT\n";
    cout << "\t\t3) GOAL MANAGEMENT\n";
    cout << "\t\t4) PROGRESS MANAGEMENT\n";
    cout << "\t\t5) NUTRITION MANAGEMENT\n";
    cout << "\t\t6) INSIGHT MANAGEMENT\n";
    cout << "\t\t7) SOCIAL MANAGEMENT\n";
    cout << "\t\t0) PRESS 0 TO EXIT\n\n";
    cout << "\t\t   Enter your choice: ";
}

// Main Function
int main() {

    displayWelcomeMessage();
    cin.get(); // Wait for user to press Enter
    User users[MAX_USERS];
    PremiumUser premium_users[MAX_PREMIUM_USERS];
    Workout workouts[MAX_WORKOUTS];
    int user_count = 0;
    int premium_user_count = 0;
    int workout_count = 0;
    int choice;

    do {
        displayMainMenu();
        cin >> choice;
        cin.ignore(); // Ignore newline character from previous input

        switch (choice) {
            case 1: { // User Management
                int user_choice;
                do {
                    displayUserMenu();
                    cin >> user_choice;
                    cin.ignore(); // Ignore newline character from previous input

                    switch (user_choice) {
                        case 1: { // Register User
                            int id, age;
                            double weight, height;
                            string name, gender, fitness_level, goals;
                            string membership_status, exclusive_workouts, personalized_insights;

                            cout << "Enter User ID: ";
                            cin >> id;
                            cin.ignore(); // Ignore newline character from previous input

                            cout << "Enter Name: ";
                            getline(cin, name);

                            cout << "Enter Age: ";
                            cin >> age;

                            cout << "Enter Weight (kg): ";
                            cin >> weight;

                            cout << "Enter Height (cm): ";
                            cin >> height;

                            cin.ignore(); // Ignore newline character from previous input

                            cout << "Enter Gender: ";
                            getline(cin, gender);

                            cout << "Enter Fitness Level: ";
                            cout<<"( ==> Begineer/Intermediate/Advanced ) : ";
                            getline(cin, fitness_level);

                            cout << "Enter Goals: ";
                            getline(cin, goals);

                            cout << "Is this a Premium User? (y/n): ";
                            char is_premium;
                            cin >> is_premium;
                            cin.ignore(); // Ignore newline character from previous input

                            if (is_premium == 'y' || is_premium == 'Y') {
                                cout << "Enter Membership Status: ";
                                getline(cin, membership_status);

                                cout << "Enter Exclusive Workouts: ";
                                getline(cin, exclusive_workouts);

                                cout << "Enter Personalized Insights: ";
                                getline(cin, personalized_insights);

                                if (premium_user_count < MAX_PREMIUM_USERS) {
                                    PremiumUser new_premium_user(id, name, age, weight, height, gender, fitness_level, goals, membership_status, exclusive_workouts, personalized_insights);
                                    premium_users[premium_user_count++] = new_premium_user;
                                    cout << "\n*** Premium User registered successfully! ***\n";
                                } else {
                                    cout << "\n*** Premium user limit reached. Cannot register more premium users. ***\n";
                                }
                            } else {
                                User new_user(id, name, age, weight, height, gender, fitness_level, goals);
                                new_user.registerUser(users, user_count, new_user);
                            }
                            break;
                        }

                        case 2: { // Remove User
                            int id;
                            cout << "Enter User ID to remove: ";
                            cin >> id;
                            cin.ignore(); // Ignore newline character from previous input

                            User temp_user;
                            temp_user.removeUser(users, user_count, id);

                            // Remove from Premium User list if exists
                            bool found = false;
                            for (int i = 0; i < premium_user_count; ++i) {
                                if (premium_users[i].getUserId() == id) {
                                    for (int j = i; j < premium_user_count - 1; ++j) {
                                        premium_users[j] = premium_users[j + 1];
                                    }
                                    --premium_user_count;
                                    found = true;
                                    break;
                                }
                            }
                            if (found) {
                                cout << "\n*** Premium User removed successfully! ***\n";
                            }
                            break;
                        }

                        case 3: { // Search User
                            int id;
                            cout << "Enter User ID to search: ";
                            cin >> id;
                            cin.ignore(); // Ignore newline character from previous input

                            User temp_user;
                            temp_user.searchUser(users, user_count, id);

                            for (int i = 0; i < premium_user_count; ++i) {
                                if (premium_users[i].getUserId() == id) {
                                    premium_users[i].viewProgress();
                                    break;
                                }
                            }
                            break;
                        }

                        case 4: { // Update User
                            int id;
                            string new_name, new_gender, new_fitness_level, new_goals;
                            int new_age;
                            double new_weight, new_height;

                            cout << "Enter User ID to update: ";
                            cin >> id;
                            cin.ignore(); // Ignore newline character from previous input

                            cout << "Enter New Name: ";
                            getline(cin, new_name);

                            cout << "Enter New Age: ";
                            cin >> new_age;

                            cout << "Enter New Weight (kg): ";
                            cin >> new_weight;

                            cout << "Enter New Height (cm): ";
                            cin >> new_height;

                            cin.ignore(); // Ignore newline character from previous input

                            cout << "Enter New Gender: ";
                            getline(cin, new_gender);

                            cout << "Enter New Fitness Level: ";
                            cout<<"==> Beginner\n";
                            cout<<"==> Intermediate\n";
                            cout<<"==> Advanced\n";
                            cout<<"\nEnter complete word : ";
                            getline(cin, new_fitness_level);

                            cout << "Enter New Goals: ";
                            getline(cin, new_goals);

                            User temp_user;
                            temp_user.updateUser(users, user_count, id, new_name, new_age, new_weight, new_height, new_gender, new_fitness_level, new_goals);

                            for (int i = 0; i < premium_user_count; ++i) {
                                if (premium_users[i].getUserId() == id) {
                                    premium_users[i].setName(new_name);
                                    premium_users[i].setAge(new_age);
                                    premium_users[i].setWeight(new_weight);
                                    premium_users[i].setHeight(new_height);
                                    premium_users[i].setGender(new_gender);
                                    premium_users[i].setFitnessLevel(new_fitness_level);
                                    premium_users[i].setGoals(new_goals);
                                    break;
                                }
                            }
                            break;
                        }

                        case 5: { // View User Progress
                            int id;
                            cout << "Enter User ID to view progress: ";
                            cin >> id;
                            cin.ignore(); // Ignore newline character from previous input

                            User temp_user;
                            temp_user.searchUser(users, user_count, id);

                            for (int i = 0; i < premium_user_count; ++i) {
                                if (premium_users[i].getUserId() == id) {
                                    premium_users[i].viewProgress();
                                    break;
                                }
                            }
                            break;
                        }

                        case 6: { // Access Premium Features
                            int id;
                            cout << "Enter Premium User ID to access features: ";
                            cin >> id;
                            cin.ignore(); // Ignore newline character from previous input

                            for (int i = 0; i < premium_user_count; ++i) {
                                if (premium_users[i].getUserId() == id) {
                                    premium_users[i].accessExclusiveWorkouts();
                                    premium_users[i].receivePersonalizedInsights();
                                    break;
                                }
                            }
                            break;
                        }

                        case 0:
                            break; // Go back to main menu
                        
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                } while (user_choice != 0);
                break;
            }

            case 2: { // Workout Management
                int workout_choice;
                do {
                    displayWorkoutMenu();
                    cin >> workout_choice;
                    cin.ignore(); // Ignore newline character from previous input

                    switch (workout_choice) {
                        case 1: { // Add Workout
                            int id, duration, user_id;
                            double calories_burned;
                            string type, date, intensity_level;

                            cout << "Enter Workout ID: ";
                            cin >> id;
                            cin.ignore(); // Ignore newline character from previous input

                            cout << "Enter Type (e.g., cardio, strength, flexibility): ";
                            getline(cin, type);

                            cout << "Enter Duration (minutes): ";
                            cin >> duration;

                            cout << "Enter Calories Burned: ";
                            cin >> calories_burned;

                            cout << "Enter Date (YYYY-MM-DD): ";
                            cin.ignore(); // Ignore newline character from previous input
                            getline(cin, date);

                            cout << "Enter User ID: ";
                            cin >> user_id;
                            cin.ignore(); // Ignore newline character from previous input

                            cout << "Enter Intensity Level (low, medium, high): ";
                            getline(cin, intensity_level);

                            Workout new_workout(id, type, duration, calories_burned, date, user_id, intensity_level);
                            new_workout.addWorkout(workouts, workout_count, new_workout);
                            break;
                        }

                        case 2: { // Remove Workout
                            int id;
                            cout << "Enter Workout ID to remove: ";
                            cin >> id;
                            cin.ignore(); // Ignore newline character from previous input

                            Workout temp_workout;
                            temp_workout.removeWorkout(workouts, workout_count, id);
                            break;
                        }

                        case 3: { // Search Workout
                            int id;
                            cout << "Enter Workout ID to search: ";
                            cin >> id;
                            cin.ignore(); // Ignore newline character from previous input

                            Workout temp_workout;
                            temp_workout.searchWorkout(workouts, workout_count, id);
                            break;
                        }

                        case 4: { // Update Workout
                            int id;
                            string new_type, new_date, new_intensity_level;
                            int new_duration;
                            double new_calories_burned;
                            int new_user_id;

                            cout << "Enter Workout ID to update: ";
                            cin >> id;
                            cin.ignore(); // Ignore newline character from previous input

                            cout << "Enter New Type: ";
                            getline(cin, new_type);

                            cout << "Enter New Duration (minutes): ";
                            cin >> new_duration;

                            cout << "Enter New Calories Burned: ";
                            cin >> new_calories_burned;

                            cout << "Enter New Date (YYYY-MM-DD): ";
                            cin.ignore(); // Ignore newline character from previous input
                            getline(cin, new_date);

                            cout << "Enter New User ID: ";
                            cin >> new_user_id;

                            cout << "Enter New Intensity Level: ";
                            cin.ignore(); // Ignore newline character from previous input
                            getline(cin, new_intensity_level);

                            Workout temp_workout;
                            temp_workout.updateWorkout(workouts, workout_count, id, new_type, new_duration, new_calories_burned, new_date, new_user_id, new_intensity_level);
                            break;
                        }

                        case 5: { // View Workouts
                            Workout temp_workout;
                            temp_workout.viewWorkouts(workouts, workout_count);
                            break;
                        }

                        case 6: { // Suggest Workouts
                            Workout temp_workout;
                            temp_workout.suggestWorkouts(users, user_count);
                            break;
                        }

                        case 0:
                            break; // Go back to main menu
                        
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                } while (workout_choice != 0);
                break;
            }

            case 3:
            {
                showGoalManagementMenu(); break;
            }
            case 4:
            {
                showProgressManagementMenu(); break;
            }
            case 5:
            {
               showNutritionManagementMenu(); break;
            }
            case 6:
            {
                showInsightsManagementMenu(); break;
            }
            case 7:
            {
                showSocialManagementMenu(); break;
            }
            case 0:
                cout << "\n\n\tExiting the program. Have a great day!\n"; break;
            default:
                cout << "\n\n\tInvalid choice. Please try again.\n"; break;
        }
    } while (choice != 0);

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////