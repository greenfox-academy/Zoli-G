void print_menu();
void promt();
void clearscreen();
void interpreter(char *command);
int is_this_a_number(char *string);
int is_this_an_operator(char *string);
void do_summation(float operand_1, float operand_2);
void do_subtraction(float operand_1, float operand_2);
void do_multiplication(float operand_1, float operand_2);
void do_division(float operand_1, float operand_2);
void do_mod(float operand_1, float operand_2);
void do_squaring(float operand_1, float operand_2);
void do_sqrt(float operand_1, float operand_2);
void do_logarithm(float operand_1, float operand_2);
void do_binto(char *operand_1, float operand_2);
void do_hexto(char *operand_1, float operand_2);
void do_decto(char *operand_1, float operand_2);
void set_cursor_pos();