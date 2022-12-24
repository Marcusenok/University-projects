#include<iostream>

struct RaggedArray
{
	int** data = NULL;
	int rows = 0;
	int* cols = NULL;
};

void hands_input(struct RaggedArray& mas);

void input_array_txt(struct RaggedArray& mas);

void input_array_bin(struct RaggedArray& mas);

void choose_zapontnie_mas(struct RaggedArray& mas);

void input_on_screen(struct RaggedArray& mas);

void element_mas(struct RaggedArray& mas);

void output_rows_and_cols(struct RaggedArray& mas);

void chooze_next_action(struct RaggedArray& mas);

void outnput_array_in_txt(struct RaggedArray& mas);

void outnput_array_in_bin(struct RaggedArray& mas);

void end(struct RaggedArray& mas);