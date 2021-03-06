/**
 * \file lines.h This file defines functions for working with arrays of strings
 */
#pragma once
#include <stdio.h>

#define REVERSE_LINES_SUCCESS 0 /**< Symbolic parameter indicating that all lines were reversed successfully */
#define REVERSE_LINES_ERROR -1  /**< Symbolic parameter indicating that an error occured while reversing lines */
#define WRITE_LINES_SUCCESS 0   /**< Symbolic parameter indicating that all lines were write successfully */
#define WRITE_LINES_ERROR -1    /**< Symbolic parameter indicating that an error occured while writing lines */

/**
 * This structure represents strings that have been stored in a buffer. Do not modify it directly
 */
typedef struct _lines_s {
    char** _lines;
    size_t _num_lines;
    char* _string_buffer;
    size_t _string_buffer_size;
} LINES;

/**
 * \brief This function reads lines and stores them in a #LINES structure
 *
 * \param[in] input_file The file from which the lines will be read
 *
 * \return A #LINES structure describing the read lines if no error, NULL if an error occured
 *
 * \remark You can free the returned structure (if it is not NULL) by calling #free_lines.
 *         This function reads lines until it encouters EOF
 */
LINES* read_lines(FILE* input_file);

/**
 * \brief This function reverses the contents of a #LINES structure without changing their order
 *
 * \param[in] lines The #LINES structure whose contents this this function will operate on
 *
 * \return #REVERSE_LINES_SUCCESS if no error occured, #REVERSE_LINES_ERROR otherwise
 */
int reverse_lines(LINES* lines);

/**
 * \brief This functions writes the contents of a #LINES structure to a file
 *
 * \param[in] lines The #LINES structure whose contents that this function will write
 * \param[in] file The file to which the lines will be written 
 *
 * \return #WRITE_LINES_SUCCESS if no error occured, #WRITE_LINES_ERROR otherwise
 */
int write_lines(const LINES* lines, FILE* file);

/**
 * \brief This function sorts the contents of a #LINES structure
 *
 * \param[in, out] lines The #LINES structure whose contents will be sorted by this function
 */
void sort_lines(LINES* lines);

/**
 * \brief This function frees the #LINES structure returned by #read_lines
 *
 * \param[out] lines The #LINES structure that this function will operate on
 */
void free_lines(LINES* lines);
