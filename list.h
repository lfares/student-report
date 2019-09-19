#define ERROR_EMPTY 1
#define SUCCESS 0

typedef struct {
    int _id;
    float study_hours;
    float grade1;
    float grade2;
} Student;

typedef Student elem;
typedef struct node Node;
typedef struct list List;

void create_list (List **l);
void insert_elem (List *l, elem x);
int remove_elem (List *l, int _id);
int print (List *l);
int report (List *l);
int average_study (List *l);
void destroy (List **l);

