class Grade {
public:
    int subjectId;
    string subjectName;
    int score;
    string date;

    Grade(int newSubjectId, string newSubjectName, int newScore, string newDate) {
        subjectId = newSubjectId;
        subjectName = newSubjectName;
        score = newScore;
        date = newDate;
    }
};