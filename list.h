typedef struct {
    int _id;
    float study_hours;
    float grade1;
    float grade2;
} Student;

typedef Student elem;
typedef struct node Node;
typedef struct list List;

void create (List **l);
void insert (List **l, elem x);
int remove (List **l, int _id);
int print (List **l);
int report (List **l);
int average_study (List **l);
void destroy (List **l);

