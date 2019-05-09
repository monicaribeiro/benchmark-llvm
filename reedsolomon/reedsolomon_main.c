//#include <stdio.h>
#include <stdlib.h>

#include "reedsolomon.h"

#define LENGTH 204 
#define N       5

#define randup() (rand() & 0xFF)

#pragma DATA_ALIGN(x, 8);


int main(void) {

/***********************************************************************************************************************************************************************************************/
// Input Data
int inputData[N][LENGTH] = {
{ 103, 198, 105, 115, 81, 255, 74, 236, 41, 205, 186, 171, 242, 251, 227, 70, 124, 194, 84, 248, 27, 232, 231, 141, 118, 90, 46, 99, 51, 159, 201, 154, 102, 50, 13, 183, 49, 88, 163, 90, 37, 93, 5, 23, 88, 233, 94, 212, 171, 178, 205, 198, 155, 180, 84, 17, 14, 130, 116, 65, 33, 61, 220, 135, 112, 233, 62, 161, 65, 225, 252, 103, 62, 1, 126, 151, 234, 220, 107, 150, 143, 56, 92, 42, 236, 176, 59, 251, 50, 175, 60, 84, 236, 24, 219, 92, 2, 26, 254, 67, 251, 250, 170, 58, 251, 41, 209, 230, 5, 60, 124, 148, 117, 216, 190, 97, 137, 249, 92, 187, 168, 153, 15, 149, 177, 235, 241, 179, 5, 239, 247, 0, 233, 161, 58, 229, 202, 11, 203, 208, 72, 71, 100, 189, 31, 35, 30, 168, 28, 123, 100, 197, 20, 115, 90, 197, 94, 75, 121, 99, 59, 112, 100, 36, 17, 158, 9, 220, 170, 212, 172, 242, 27, 16, 175, 59, 51, 205, 227, 80, 72, 71, 21, 92, 187, 111, 34, 25, 186, 155, 125, 245, 11, 225, 26, 28, 127, 35, 248, 41, 248, 164, 27, 19 }
,
{ 4, 244, 236, 11, 185, 32, 186, 134, 195, 62, 5, 241, 236, 217, 103, 51, 183, 153, 80, 163, 227, 20, 211, 217, 52, 247, 94, 160, 242, 16, 168, 246, 5, 148, 1, 190, 180, 188, 68, 120, 250, 73, 105, 230, 35, 208, 26, 218, 105, 106, 126, 76, 126, 81, 37, 179, 72, 132, 83, 58, 148, 251, 49, 153, 144, 50, 87, 68, 238, 155, 188, 233, 229, 37, 207, 8, 245, 233, 226, 94, 83, 96, 170, 210, 178, 208, 133, 250, 84, 216, 53, 232, 212, 102, 130, 100, 152, 217, 168, 135, 117, 101, 112, 90, 138, 63, 98, 128, 41, 68, 222, 124, 165, 137, 78, 87, 89, 211, 81, 173, 172, 134, 149, 128, 236, 23, 228, 133, 241, 140, 12, 102, 241, 124, 192, 124, 187, 34, 252, 228, 102, 218, 97, 11, 99, 175, 98, 188, 131, 180, 105, 47, 58, 255, 175, 39, 22, 147, 172, 7, 31, 184, 109, 17, 52, 45, 141, 239, 79, 137, 212, 182, 99, 53, 193, 199, 228, 36, 131, 103, 216, 237, 150, 18, 236, 69, 57, 2, 216, 229, 10, 248, 157, 119, 9, 209, 165, 150, 193, 244, 31, 149, 170, 130 }
,
{ 10, 97, 3, 209, 188, 167, 13, 190, 155, 191, 171, 14, 213, 152, 1, 214, 229, 242, 214, 246, 125, 62, 197, 22, 142, 33, 46, 45, 175, 2, 198, 185, 99, 201, 138, 31, 112, 151, 222, 12, 86, 137, 26, 43, 33, 27, 1, 7, 13, 216, 253, 139, 22, 194, 161, 164, 227, 207, 210, 146, 210, 152, 75, 53, 97, 213, 85, 209, 108, 51, 221, 194, 188, 247, 237, 222, 19, 239, 229, 32, 199, 226, 171, 221, 164, 77, 129, 136, 28, 83, 26, 238, 235, 102, 36, 76, 59, 121, 30, 168, 172, 251, 106, 104, 243, 88, 70, 6, 71, 43, 38, 14, 13, 210, 235, 178, 31, 108, 58, 59, 192, 84, 42, 171, 186, 78, 248, 246, 199, 22, 158, 115, 17, 8, 219, 4, 96, 34, 10, 167, 77, 49, 181, 91, 3, 160, 13, 34, 13, 71, 93, 205, 155, 135, 120, 86, 213, 112, 76, 156, 134, 234, 15, 152, 242, 235, 156, 83, 13, 167, 250, 90, 216, 176, 181, 219, 80, 194, 253, 93, 9, 90, 42, 165, 226, 163, 251, 183, 19, 71, 84, 154, 49, 99, 50, 35, 78, 206, 118, 91, 117, 113, 182, 77 }
,
{ 113, 255, 202, 77, 181, 168, 138, 7, 94, 225, 9, 51, 166, 85, 87, 59, 29, 238, 240, 47, 110, 32, 2, 73, 129, 226, 160, 127, 248, 227, 71, 105, 227, 17, 182, 152, 185, 65, 159, 24, 34, 168, 75, 200, 253, 162, 4, 26, 144, 244, 73, 254, 21, 75, 72, 150, 45, 232, 21, 37, 203, 92, 143, 174, 109, 69, 70, 39, 134, 229, 63, 169, 141, 138, 113, 138, 44, 117, 164, 188, 106, 238, 186, 127, 57, 2, 21, 103, 234, 43, 140, 182, 135, 27, 100, 245, 97, 171, 28, 231, 144, 91, 144, 30, 229, 2, 168, 17, 119, 77, 205, 225, 59, 135, 96, 116, 138, 118, 219, 116, 161, 104, 42, 40, 131, 143, 29, 228, 58, 57, 204, 202, 148, 92, 232, 121, 94, 145, 138, 214, 222, 87, 183, 25, 223, 24, 141, 105, 142, 105, 221, 47, 209, 8, 87, 84, 151, 117, 57, 209, 174, 5, 155, 67, 97, 132, 188, 192, 21, 71, 150, 243, 158, 77, 12, 125, 101, 153, 230, 243, 2, 196, 34, 211, 204, 122, 40, 99, 239, 97, 52, 157, 102, 207, 224, 199, 83, 157, 135, 104, 228, 29, 91, 130 }
,
{ 234, 140, 204, 213, 21, 98, 35, 202, 154, 16, 155, 125, 46, 239, 5, 71, 30, 230, 211, 186, 17, 207, 104, 177, 124, 139, 26, 27, 90, 249, 223, 68, 133, 172, 26, 154, 14, 61, 100, 168, 77, 0, 38, 123, 239, 43, 195, 13, 17, 150, 200, 35, 102, 48, 212, 226, 187, 238, 253, 21, 231, 220, 90, 108, 136, 116, 7, 150, 177, 107, 63, 254, 107, 101, 121, 90, 144, 60, 104, 161, 211, 48, 196, 57, 96, 152, 27, 27, 135, 24, 49, 110, 244, 139, 219, 125, 255, 226, 19, 176, 77, 82, 174, 185, 183, 39, 19, 71, 100, 123, 233, 55, 171, 173, 112, 11, 70, 139, 39, 205, 163, 88, 59, 151, 227, 22, 20, 226, 248, 40, 146, 70, 122, 64, 255, 50, 103, 18, 121, 203, 142, 98, 2, 57, 16, 114, 69, 86, 253, 108, 35, 160, 196, 94, 56, 167, 117, 76, 137, 109, 116, 27, 179, 239, 91, 178, 33, 194, 197, 154, 142, 83, 253, 144, 140, 13, 3, 209, 99, 0, 61, 134, 161, 1, 228, 217, 168, 89, 37, 49, 199, 154, 76, 122, 137, 167, 45, 170, 106, 242, 68, 248, 69, 65 }
/*,
{ 60, 197, 8, 183, 78, 176, 228, 248, 26, 214, 61, 18, 27, 126, 154, 236, 205, 38, 143, 126, 178, 112, 182, 223, 82, 210, 229, 220, 71, 16, 152, 132, 214, 161, 59, 36, 81, 31, 29, 107, 245, 90, 125, 16, 216, 23, 252, 165, 61, 140, 36, 239, 252, 218, 206, 78, 172, 179, 42, 243, 196, 195, 119, 154, 100, 178, 190, 181, 209, 219, 32, 198, 53, 157, 214, 14, 180, 211, 179, 242, 95, 215, 225, 91, 177, 176, 169, 93, 99, 211, 81, 39, 150, 200, 193, 250, 123, 128, 175, 76, 91, 207, 19, 145, 108, 233, 159, 33, 188, 82, 19, 27, 42, 244, 118, 219, 164, 31, 57, 8, 243, 138, 47, 137, 82, 241, 132, 205, 113, 51, 26, 204, 3, 45, 93, 111, 22, 252, 144, 211, 79, 163, 238, 121, 152, 101, 84, 60, 132, 141, 68, 119, 23, 116, 1, 106, 101, 133, 55, 214, 184, 81, 162, 187, 126, 0, 43, 149, 252, 187, 104, 75, 95, 86, 196, 247, 187, 25, 51, 64, 166, 120, 183, 190, 236, 184, 40, 81, 61, 95, 39, 246, 177, 201, 177, 47, 201, 220, 196, 198, 152, 44, 17, 247 }
,
{ 149, 153, 54, 83, 133, 238, 123, 214, 44, 219, 253, 34, 140, 199, 211, 187, 144, 176, 128, 86, 72, 172, 104, 63, 47, 62, 45, 110, 45, 78, 236, 194, 232, 34, 22, 109, 17, 145, 68, 61, 108, 65, 95, 248, 8, 50, 180, 153, 226, 52, 239, 42, 224, 87, 105, 16, 149, 150, 126, 194, 229, 106, 133, 205, 141, 155, 58, 158, 44, 126, 219, 153, 192, 58, 145, 200, 108, 69, 97, 79, 121, 81, 121, 90, 168, 227, 106, 62, 121, 232, 0, 94, 82, 133, 43, 223, 32, 102, 125, 77, 228, 88, 230, 164, 146, 119, 109, 255, 189, 206, 78, 54, 31, 199, 144, 200, 170, 250, 6, 36, 226, 6, 130, 53, 140, 174, 20, 172, 20, 146, 249, 248, 234, 223, 157, 125, 87, 10, 124, 20, 216, 202, 74, 248, 145, 219, 192, 60, 213, 198, 96, 184, 204, 226, 237, 88, 144, 1, 5, 164, 147, 254, 157, 126, 222, 58, 251, 53, 68, 119, 73, 28, 65, 147, 20, 210, 110, 212, 14, 68, 154, 110, 252, 103, 81, 233, 191, 225, 234, 196, 134, 126, 195, 35, 252, 161, 93, 247, 214, 161, 110, 31, 189, 175 }
,
{58, 103, 220, 192, 48, 127, 153, 150, 172, 124, 75, 82, 67, 255, 2, 37, 86, 34, 250, 100, 54, 88, 235, 118, 165, 48, 58, 241, 7, 65, 137, 65, 168, 102, 2, 216, 229, 155, 110, 145, 24, 185, 227, 91, 184, 230, 129, 14, 8, 123, 114, 62, 211, 94, 180, 121, 142, 238, 106, 149, 47, 243, 215, 215, 89, 217, 175, 62, 116, 29, 207, 140, 215, 179, 232, 143, 153, 105, 158, 161, 228, 16, 223, 184, 110, 147, 49, 253, 129, 155, 146, 177, 142, 105, 136, 232, 66, 56, 38, 183, 85, 246, 67, 44, 169, 43, 188, 66, 148, 90, 227, 121, 106, 194, 49, 217, 85, 98, 214, 214, 253, 104, 135, 139, 210, 16, 115, 20, 72, 154, 203, 157, 144, 15, 202, 57, 58, 134, 123, 207, 224, 94, 72, 74, 32, 121, 35, 117, 219, 249, 75, 216, 98, 211, 99, 52, 227, 215, 72, 43, 113, 20, 200, 1, 35, 146, 58, 93, 24, 181, 44, 248, 19, 116, 67, 51, 237, 102, 168, 200, 96, 243, 160, 194, 198, 4, 246, 169, 219, 62, 212, 76, 82, 157, 77, 117, 47, 135, 211, 72, 60, 255, 64, 79 }
,
{ 230, 154, 138, 254, 28, 15, 40, 189, 79, 36, 188, 134, 78, 92, 17, 179, 79, 254, 58, 200, 238, 174, 169, 96, 96, 75, 110, 195, 75, 136, 41, 49, 34, 179, 48, 62, 194, 88, 251, 18, 124, 183, 152, 202, 20, 169, 125, 99, 167, 183, 43, 149, 101, 213, 245, 197, 32, 99, 136, 107, 236, 178, 156, 14, 101, 204, 77, 40, 36, 72, 58, 160, 0, 210, 106, 20, 124, 232, 119, 35, 159, 163, 185, 5, 120, 174, 202, 152, 18, 83, 3, 254, 5, 159, 12, 106, 108, 89, 146, 144, 162, 204, 49, 162, 159, 155, 182, 27, 131, 45, 62, 35, 208, 247, 40, 72, 166, 242, 224, 184, 69, 227, 182, 74, 131, 194, 181, 239, 28, 71, 127, 190, 20, 176, 96, 179, 76, 22, 206, 207, 67, 12, 242, 20, 4, 26, 92, 170, 13, 61, 98, 82, 32, 24, 157, 163, 218, 82, 146, 246, 153, 18, 180, 173, 194, 20, 96, 14, 42, 46, 222, 110, 59, 208, 130, 63, 235, 222, 233, 248, 27, 75, 74, 60, 99, 231, 223, 61, 57, 114, 52, 211, 132, 232, 128, 70, 253, 225, 85, 39, 15, 51, 149, 74 }
,
{ 17, 189, 49, 77, 32, 24, 45, 94, 82, 159, 146, 37, 35, 122, 165, 105, 119, 134, 190, 159, 150, 241, 52, 224, 245, 76, 106, 227, 66, 220, 202, 83, 154, 251, 161, 186, 19, 206, 24, 101, 109, 170, 138, 144, 37, 48, 249, 156, 182, 184, 59, 76, 169, 112, 45, 158, 188, 151, 130, 254, 115, 76, 81, 13, 71, 242, 200, 90, 192, 224, 192, 45, 139, 74, 189, 176, 122, 183, 76, 49, 111, 136, 125, 24, 248, 170, 183, 180, 65, 57, 178, 181, 133, 3, 194, 204, 246, 138, 38, 182, 107, 230, 228, 246, 49, 161, 166, 171, 88, 242, 220, 199, 122, 90, 224, 114, 4, 151, 38, 70, 208, 216, 251, 85, 220, 189, 33, 210, 72, 71, 136, 179, 46, 108, 169, 95, 14, 79, 10, 102, 65, 231, 46, 188, 65, 14, 46, 69, 165, 85, 139, 117, 45, 134, 202, 9, 68, 235, 219, 140, 50, 100, 63, 96, 208, 232, 191, 222, 55, 202, 69, 120, 177, 115, 52, 242, 129, 99, 55, 38, 184, 195, 155, 229, 73, 101, 239, 141, 80, 202, 25, 130, 46, 88, 227, 255, 64, 162, 221, 119, 108, 34, 240, 29 }
*/
};

// Number of errors per array (max value: 127)
int k[N]={ 103, 104, 63, 94, 108 /*, 87, 97, 114, 9, 45*/ };

// Indexes of the array where the errors will be included
int pos[N][127] = {
{ 202, 187, 139, 48, 121, 31, 19, 22, 30, 184, 8, 141, 158, 55, 79, 66, 102, 135, 112, 82, 9, 23, 193, 200, 162, 130, 140, 57, 50, 73, 129, 3, 137, 141, 65, 99, 81, 51, 116, 38, 48, 194, 108, 155, 31, 84, 36, 136, 174, 167, 118, 58, 57, 14, 180, 68, 92, 85, 53, 155, 9, 193, 71, 167, 19, 100, 141, 5, 11, 116, 147, 89, 191, 108, 83, 201, 119, 85, 135, 179, 52, 164, 182, 136, 136, 130, 104, 63, 61, 4, 179, 184, 11, 157, 115, 97, 157, 104, 99, 201, 160, 187, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 76, 180, 141, 149, 140, 138, 74, 52, 172, 89, 158, 177, 30, 121, 63, 140, 2, 179, 118, 124, 83, 9, 73, 142, 120, 16, 102, 8, 114, 44, 42, 60, 44, 135, 32, 165, 189, 145, 184, 175, 59, 123, 1, 38, 134, 164, 10, 168, 132, 165, 103, 23, 172, 171, 200, 126, 78, 37, 49, 143, 105, 103, 200, 41, 191, 36, 0, 202, 176, 198, 184, 176, 37, 86, 160, 14, 2, 48, 5, 75, 168, 158, 119, 9, 198, 136, 71, 109, 65, 68, 169, 30, 148, 118, 116, 18, 48, 196, 78, 132, 157, 123, 121, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 150, 9, 186, 125, 94, 49, 41, 4, 69, 40, 176, 177, 108, 105, 80, 127, 116, 2, 189, 31, 74, 111, 29, 78, 107, 194, 104, 63, 113, 168, 1, 91, 100, 11, 93, 112, 71, 156, 82, 20, 21, 140, 126, 81, 41, 177, 9, 159, 30, 142, 161, 164, 146, 154, 18, 162, 56, 37, 46, 166, 36, 1, 151, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 54, 116, 108, 86, 57, 35, 92, 63, 10, 118, 80, 102, 145, 117, 137, 113, 97, 113, 141, 163, 69, 99, 24, 38, 197, 174, 61, 189, 58, 13, 125, 130, 25, 171, 186, 32, 149, 161, 166, 79, 99, 53, 198, 110, 13, 196, 123, 104, 110, 186, 150, 16, 93, 140, 120, 35, 141, 123, 203, 188, 102, 99, 176, 41, 19, 47, 61, 9, 189, 158, 113, 69, 154, 186, 95, 38, 95, 90, 8, 98, 102, 146, 157, 61, 49, 45, 158, 85, 179, 58, 186, 11, 105, 169, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 139, 154, 107, 110, 47, 56, 170, 93, 177, 132, 131, 174, 162, 76, 165, 188, 23, 52, 200, 10, 83, 54, 158, 78, 92, 195, 28, 195, 162, 70, 2, 171, 64, 104, 54, 51, 53, 135, 200, 10, 91, 185, 39, 182, 192, 144, 178, 168, 131, 47, 131, 66, 76, 63, 82, 33, 22, 89, 139, 7, 191, 194, 135, 151, 46, 195, 93, 29, 3, 113, 113, 131, 33, 70, 159, 172, 177, 55, 140, 43, 73, 160, 41, 3, 26, 78, 136, 147, 22, 10, 39, 148, 88, 69, 79, 6, 96, 191, 100, 129, 55, 137, 10, 29, 170, 34, 93, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
/*,
{ 111, 134, 159, 192, 17, 42, 127, 139, 177, 141, 28, 173, 156, 32, 168, 190, 110, 44, 22, 7, 30, 200, 89, 160, 6, 65, 91, 177, 161, 50, 38, 73, 180, 86, 23, 114, 15, 159, 194, 115, 161, 107, 87, 39, 34, 42, 73, 17, 29, 199, 68, 54, 168, 136, 200, 27, 176, 77, 86, 52, 77, 65, 6, 71, 133, 36, 49, 29, 175, 44, 160, 125, 77, 141, 191, 28, 160, 163, 123, 149, 45, 125, 19, 56, 63, 34, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 196, 38, 168, 131, 59, 64, 15, 119, 88, 65, 68, 110, 155, 168, 125, 148, 101, 93, 33, 42, 65, 62, 21, 96, 26, 35, 124, 100, 24, 198, 136, 11, 148, 175, 73, 147, 68, 90, 187, 70, 15, 179, 123, 163, 12, 42, 120, 130, 30, 119, 63, 113, 143, 92, 58, 7, 139, 33, 134, 155, 99, 167, 46, 156, 67, 127, 5, 133, 112, 147, 55, 191, 9, 74, 166, 162, 18, 152, 91, 89, 124, 161, 49, 23, 60, 75, 197, 55, 159, 146, 26, 54, 102, 56, 56, 20, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 155, 77, 153, 59, 113, 68, 25, 59, 95, 73, 137, 68, 4, 95, 115, 111, 114, 126, 104, 1, 51, 2, 139, 94, 173, 118, 191, 53, 144, 124, 170, 70, 167, 145, 202, 30, 88, 201, 42, 131, 3, 65, 52, 58, 64, 199, 161, 187, 82, 140, 19, 1, 75, 131, 165, 0, 128, 159, 56, 44, 143, 99, 53, 172, 31, 87, 151, 157, 86, 87, 167, 164, 101, 67, 80, 150, 23, 67, 75, 159, 92, 28, 130, 86, 15, 83, 133, 70, 34, 60, 121, 81, 127, 168, 132, 53, 165, 8, 139, 127, 65, 5, 126, 177, 84, 19, 115, 93, 197, 188, 52, 17, 67, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 51, 134, 34, 132, 49, 65, 55, 69, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 38, 18, 153, 52, 9, 95, 28, 8, 30, 38, 134, 76, 130, 158, 72, 127, 178, 148, 128, 16, 177, 12, 183, 111, 106, 20, 95, 201, 60, 127, 90, 62, 67, 63, 79, 78, 10, 1, 187, 202, 133, 74, 191, 198, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
*/
};

// Errors that will be included in array
int noise[N][127] = {
{ 105, 81, 74, 41, 186, 242, 227, 124, 84, 27, 231, 118, 46, 51, 201, 102, 13, 49, 163, 37, 5, 88, 94, 171, 205, 155, 84, 14, 116, 33, 220, 112, 62, 65, 252, 62, 126, 234, 107, 143, 92, 236, 59, 50, 60, 236, 219, 2, 254, 251, 170, 251, 209, 5, 124, 117, 190, 137, 92, 168, 15, 177, 241, 5, 247, 233, 58, 202, 203, 72, 100, 31, 30, 28, 100, 20, 90, 94, 121, 59, 100, 17, 9, 170, 172, 27, 175, 51, 227, 72, 21, 187, 34, 186, 125, 11, 26, 127, 248, 248, 27, 181, 78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 50, 224, 77, 52, 95, 119, 203, 5, 134, 43, 26, 162, 112, 115, 4, 211, 148, 175, 240, 158, 50, 73, 130, 169, 112, 178, 41, 72, 10, 213, 24, 68, 91, 142, 215, 155, 66, 6, 51, 205, 132, 45, 212, 71, 50, 236, 196, 246, 35, 108, 178, 4, 236, 185, 186, 195, 5, 236, 103, 183, 80, 227, 211, 52, 94, 242, 168, 5, 1, 180, 68, 250, 105, 35, 26, 105, 126, 126, 37, 72, 83, 148, 49, 144, 87, 238, 188, 229, 207, 245, 226, 83, 170, 178, 133, 84, 53, 212, 130, 152, 168, 117, 112, 138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 128, 68, 124, 137, 87, 211, 173, 134, 128, 23, 133, 140, 102, 124, 124, 34, 228, 218, 11, 175, 188, 180, 47, 255, 39, 147, 7, 184, 17, 45, 239, 137, 182, 53, 199, 36, 103, 237, 18, 69, 2, 229, 248, 119, 209, 150, 244, 149, 130, 108, 174, 205, 104, 172, 166, 180, 202, 178, 55, 203, 207, 201, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 3, 218, 215, 25, 210, 153, 121, 0, 86, 212, 209, 228, 205, 163, 198, 255, 42, 21, 67, 238, 2, 97, 19, 158, 252, 129, 113, 166, 171, 207, 75, 58, 167, 118, 126, 255, 235, 253, 195, 103, 13, 140, 78, 189, 124, 106, 91, 60, 244, 237, 22, 243, 77, 0, 139, 207, 80, 23, 142, 152, 97, 209, 167, 190, 191, 14, 152, 214, 242, 246, 62, 22, 33, 45, 2, 185, 201, 31, 151, 12, 137, 43, 27, 7, 216, 139, 194, 164, 207, 146, 152, 53, 213, 209, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 221, 188, 237, 19, 229, 199, 171, 164, 129, 28, 26, 235, 36, 59, 30, 172, 106, 243, 70, 71, 38, 13, 235, 31, 58, 192, 42, 186, 248, 199, 158, 17, 219, 96, 10, 77, 181, 3, 13, 13, 93, 155, 120, 213, 76, 134, 15, 242, 156, 13, 250, 216, 181, 80, 253, 9, 42, 226, 251, 19, 84, 49, 50, 78, 118, 117, 182, 33, 40, 46, 207, 128, 220, 156, 25, 30, 74, 209, 115, 74, 123, 90, 13, 156, 237, 91, 2, 181, 61, 182, 2, 196, 36, 200, 181, 128, 210, 97, 86, 22, 200, 255, 77, 168, 7, 225, 51, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
/*,
{ 29, 240, 110, 2, 129, 160, 248, 71, 227, 182, 185, 159, 34, 75, 253, 4, 144, 73, 21, 72, 45, 21, 203, 143, 109, 70, 134, 63, 141, 113, 44, 164, 106, 186, 57, 21, 234, 140, 135, 100, 97, 28, 144, 144, 229, 168, 119, 205, 59, 96, 138, 219, 161, 42, 131, 29, 58, 204, 148, 232, 94, 138, 222, 183, 223, 141, 142, 221, 209, 87, 151, 57, 174, 155, 97, 188, 21, 150, 158, 12, 101, 230, 2, 34, 204, 40, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 157, 207, 199, 157, 104, 29, 130, 103, 208, 230, 3, 230, 118, 255, 79, 13, 198, 205, 48, 21, 78, 244, 157, 209, 93, 50, 98, 55, 121, 178, 150, 181, 156, 234, 237, 102, 49, 13, 182, 61, 149, 116, 135, 208, 226, 201, 65, 213, 1, 171, 190, 43, 107, 190, 22, 53, 106, 163, 85, 242, 245, 175, 58, 20, 67, 42, 208, 241, 141, 94, 171, 79, 61, 7, 101, 201, 181, 144, 253, 43, 100, 66, 171, 113, 226, 220, 98, 163, 29, 49, 164, 220, 115, 73, 17, 176, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 117, 28, 8, 137, 77, 56, 209, 30, 135, 47, 140, 43, 173, 172, 105, 206, 196, 140, 213, 98, 202, 16, 125, 239, 71, 230, 186, 207, 177, 139, 27, 249, 68, 172, 154, 61, 168, 0, 123, 43, 13, 150, 35, 48, 226, 238, 21, 220, 108, 116, 150, 107, 254, 101, 90, 60, 161, 48, 57, 152, 27, 24, 110, 139, 125, 226, 176, 82, 185, 39, 71, 123, 55, 173, 11, 139, 205, 88, 151, 22, 226, 40, 70, 64, 50, 18, 203, 98, 57, 114, 86, 108, 160, 94, 167, 76, 109, 27, 239, 178, 194, 154, 83, 144, 13, 209, 0, 134, 1, 217, 89, 49, 154, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 45, 106, 68, 69, 136, 78, 163, 140, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 28, 138, 43, 60, 8, 78, 228, 26, 61, 27, 154, 205, 143, 178, 182, 82, 229, 71, 152, 214, 59, 81, 29, 245, 125, 216, 252, 61, 36, 252, 206, 172, 42, 196, 119, 100, 190, 209, 32, 53, 214, 180, 179, 95, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
*/
};

// Output Data
int expectedResult[N][LENGTH] = {
{ 103, 198, 105, 112, 72, 202, 74, 236, 231, 15, 186, 34, 242, 251, 78, 70, 124, 194, 84, 247, 27, 232, 124, 88, 118, 90, 46, 99, 51, 159, 84, 60, 102, 50, 13, 183, 219, 88, 143, 90, 37, 93, 5, 23, 88, 233, 94, 212, 92, 178, 116, 234, 100, 92, 84, 51, 14, 209, 251, 65, 33, 227, 220, 51, 112, 252, 102, 161, 117, 225, 252, 241, 62, 33, 126, 151, 234, 220, 107, 201, 143, 126, 37, 100, 236, 94, 59, 251, 50, 31, 60, 84, 190, 24, 219, 92, 2, 11, 254, 248, 233, 250, 13, 58, 127, 41, 209, 230, 28, 60, 124, 148, 163, 216, 190, 125, 72, 249, 170, 90, 168, 186, 15, 149, 177, 235, 241, 179, 5, 220, 27, 0, 233, 161, 58, 121, 172, 62, 203, 74, 84, 58, 100, 189, 31, 35, 30, 100, 28, 123, 100, 197, 20, 115, 90, 168, 94, 26, 46, 99, 27, 112, 205, 36, 17, 158, 9, 5, 170, 212, 172, 242, 27, 16, 254, 59, 51, 205, 227, 21, 124, 71, 9, 92, 187, 111, 34, 181, 125, 19, 252, 40, 84, 196, 55, 137, 30, 238, 116, 126, 27, 147, 91, 7 }
,
{ 168, 212, 126, 11, 185, 37, 138, 134, 72, 144, 196, 241, 236, 217, 105, 51, 178, 153, 84, 163, 227, 20, 211, 4, 52, 247, 94, 160, 242, 16, 83, 246, 215, 148, 1, 190, 242, 105, 71, 120, 250, 52, 24, 230, 91, 208, 26, 218, 53, 103, 126, 76, 5, 81, 37, 179, 72, 132, 83, 132, 68, 251, 49, 4, 144, 207, 87, 68, 245, 155, 188, 188, 229, 130, 203, 72, 50, 233, 130, 94, 83, 96, 170, 50, 178, 208, 35, 250, 84, 43, 53, 232, 212, 102, 130, 100, 152, 217, 168, 135, 117, 101, 41, 227, 138, 80, 98, 128, 41, 229, 222, 124, 165, 137, 10, 87, 133, 211, 178, 49, 112, 112, 149, 117, 158, 23, 195, 133, 241, 140, 12, 102, 152, 124, 50, 142, 238, 34, 119, 228, 211, 77, 169, 183, 99, 6, 98, 188, 170, 52, 105, 47, 58, 255, 175, 39, 22, 168, 148, 7, 26, 184, 109, 17, 236, 108, 141, 239, 83, 226, 212, 185, 236, 53, 193, 205, 250, 162, 131, 175, 224, 237, 150, 18, 68, 69, 57, 2, 225, 144, 172, 102, 188, 43, 148, 127, 131, 91, 53, 18, 224, 126, 190, 157 }
,
{ 10, 201, 218, 209, 134, 167, 13, 190, 155, 244, 171, 53, 213, 152, 1, 214, 229, 242, 166, 246, 69, 2, 197, 22, 142, 33, 46, 45, 175, 47, 130, 175, 99, 201, 138, 31, 207, 178, 222, 12, 23, 209, 26, 43, 33, 27, 55, 7, 13, 211, 253, 139, 22, 194, 161, 164, 202, 207, 210, 146, 210, 152, 75, 184, 97, 213, 85, 209, 108, 128, 221, 103, 188, 247, 188, 222, 19, 239, 255, 32, 124, 119, 18, 221, 164, 77, 129, 136, 28, 83, 26, 137, 235, 199, 87, 76, 59, 121, 30, 168, 182, 251, 106, 104, 7, 124, 70, 39, 102, 43, 38, 180, 36, 17, 235, 178, 228, 108, 58, 59, 192, 84, 42, 171, 186, 137, 248, 34, 199, 22, 158, 115, 17, 8, 219, 4, 96, 34, 10, 167, 229, 49, 108, 91, 3, 160, 104, 34, 13, 71, 128, 128, 155, 135, 172, 86, 237, 112, 76, 149, 134, 174, 180, 152, 205, 235, 203, 83, 45, 167, 250, 90, 216, 176, 181, 219, 133, 150, 253, 93, 9, 90, 42, 165, 226, 163, 124, 183, 247, 70, 79, 125, 99, 181, 218, 234, 13, 138, 12, 106, 179, 191, 201, 179 }
,
{ 113, 255, 202, 77, 181, 168, 138, 7, 151, 214, 86, 53, 166, 124, 87, 59, 243, 238, 240, 191, 110, 32, 2, 73, 19, 167, 160, 127, 248, 227, 71, 105, 255, 17, 182, 207, 185, 65, 185, 24, 34, 190, 75, 200, 253, 139, 4, 14, 144, 216, 73, 254, 21, 140, 3, 150, 45, 210, 146, 37, 203, 7, 143, 0, 109, 69, 70, 39, 134, 22, 63, 169, 141, 138, 113, 138, 44, 117, 164, 103, 209, 238, 186, 127, 57, 164, 25, 103, 234, 43, 31, 182, 121, 77, 100, 201, 97, 42, 12, 209, 144, 91, 137, 30, 60, 213, 168, 17, 215, 77, 244, 225, 59, 62, 96, 116, 218, 163, 212, 116, 139, 104, 42, 23, 131, 75, 29, 228, 58, 57, 58, 202, 148, 92, 232, 121, 94, 198, 138, 214, 0, 80, 183, 25, 223, 205, 43, 105, 142, 235, 22, 47, 209, 8, 33, 84, 151, 27, 194, 209, 174, 253, 155, 238, 97, 132, 195, 192, 21, 209, 150, 118, 158, 77, 129, 125, 167, 153, 230, 207, 2, 196, 34, 211, 204, 122, 152, 99, 138, 51, 250, 252, 97, 192, 117, 73, 235, 216, 63, 19, 79, 2, 6, 121 }
,
{ 234, 140, 158, 156, 21, 98, 128, 19, 154, 16, 77, 125, 46, 239, 5, 71, 30, 230, 211, 186, 17, 207, 61, 106, 124, 139, 237, 27, 42, 168, 223, 68, 133, 220, 225, 154, 14, 61, 100, 2, 77, 13, 85, 74, 239, 43, 118, 13, 17, 150, 200, 77, 243, 181, 10, 200, 199, 238, 253, 21, 231, 220, 90, 80, 219, 116, 216, 150, 177, 200, 156, 254, 107, 123, 121, 90, 181, 60, 91, 181, 211, 48, 253, 38, 96, 152, 27, 27, 36, 226, 49, 93, 58, 51, 219, 125, 210, 226, 19, 176, 86, 82, 174, 185, 96, 39, 19, 237, 100, 123, 19, 55, 171, 207, 112, 11, 70, 139, 39, 205, 163, 88, 59, 151, 227, 22, 20, 226, 248, 22, 146, 128, 28, 64, 255, 50, 2, 255, 121, 251, 115, 98, 2, 57, 134, 114, 69, 181, 196, 108, 35, 78, 196, 94, 188, 167, 117, 76, 235, 25, 90, 27, 248, 239, 91, 30, 33, 194, 242, 154, 7, 17, 30, 144, 235, 13, 3, 74, 15, 0, 61, 134, 213, 1, 228, 155, 168, 89, 70, 19, 119, 65, 249, 225, 99, 195, 78, 251, 80, 138, 30, 50, 50, 228 }
/*,
{ 60, 197, 8, 183, 78, 176, 222, 72, 26, 214, 61, 18, 27, 126, 154, 234, 205, 205, 143, 2, 178, 112, 21, 57, 82, 210, 229, 29, 188, 221, 45, 132, 75, 161, 40, 36, 141, 31, 44, 144, 245, 90, 168, 239, 87, 101, 252, 165, 61, 142, 113, 239, 232, 218, 219, 78, 34, 179, 42, 243, 196, 195, 119, 204, 100, 138, 190, 181, 138, 219, 32, 183, 53, 119, 214, 14, 180, 174, 179, 242, 95, 215, 225, 91, 177, 176, 148, 144, 99, 203, 81, 134, 150, 200, 193, 250, 123, 128, 175, 76, 91, 207, 19, 145, 108, 233, 159, 28, 188, 82, 144, 29, 42, 244, 21, 100, 164, 31, 57, 8, 243, 138, 47, 158, 82, 230, 132, 248, 113, 51, 26, 204, 3, 223, 240, 111, 42, 252, 144, 71, 79, 155, 238, 121, 152, 101, 84, 60, 132, 12, 68, 119, 23, 116, 1, 106, 34, 133, 55, 140, 21, 97, 162, 150, 126, 0, 43, 149, 161, 187, 104, 75, 95, 159, 196, 209, 58, 63, 51, 64, 106, 120, 183, 190, 236, 184, 40, 81, 153, 207, 57, 168, 244, 69, 209, 168, 234, 119, 175, 199, 105, 168, 47, 111 }
,
{ 149, 153, 54, 83, 133, 208, 123, 53, 44, 61, 253, 181, 226, 199, 211, 149, 144, 176, 181, 86, 176, 157, 104, 113, 121, 62, 164, 110, 45, 78, 202, 194, 232, 163, 22, 50, 17, 145, 207, 61, 108, 65, 201, 248, 8, 50, 58, 153, 226, 171, 239, 42, 224, 87, 220, 163, 17, 150, 22, 104, 226, 106, 244, 190, 29, 78, 58, 67, 49, 126, 61, 153, 192, 237, 7, 220, 108, 69, 97, 79, 121, 81, 121, 90, 168, 227, 106, 62, 208, 43, 13, 253, 190, 205, 43, 223, 209, 102, 125, 245, 55, 198, 115, 164, 146, 119, 109, 255, 189, 206, 230, 54, 141, 43, 144, 200, 170, 250, 6, 171, 65, 6, 130, 135, 100, 79, 20, 42, 20, 146, 213, 157, 234, 241, 85, 125, 150, 10, 124, 106, 216, 202, 74, 107, 145, 219, 49, 94, 156, 198, 96, 184, 144, 226, 237, 242, 20, 1, 5, 29, 147, 66, 201, 208, 222, 58, 101, 175, 255, 119, 73, 28, 65, 147, 20, 234, 110, 212, 14, 116, 154, 110, 252, 103, 81, 233, 191, 182, 229, 20, 214, 30, 35, 8, 153, 59, 186, 223, 108, 184, 17, 221, 222, 145 }
,
{ 60, 107, 16, 13, 173, 154, 153, 150, 27, 124, 75, 82, 67, 255, 2, 50, 86, 49, 250, 209, 54, 88, 235, 205, 165, 209, 58, 241, 40, 65, 61, 125, 168, 102, 57, 216, 229, 155, 110, 145, 24, 185, 123, 91, 152, 230, 129, 14, 8, 123, 114, 202, 122, 76, 180, 121, 57, 238, 48, 30, 114, 243, 215, 215, 226, 194, 175, 154, 43, 29, 98, 140, 215, 47, 232, 151, 153, 28, 158, 161, 11, 108, 108, 18, 13, 147, 64, 39, 168, 155, 146, 177, 226, 134, 239, 172, 66, 56, 38, 24, 85, 55, 67, 44, 213, 43, 188, 66, 148, 90, 227, 206, 106, 77, 196, 0, 85, 98, 230, 214, 253, 86, 135, 139, 139, 16, 83, 178, 161, 154, 70, 101, 167, 203, 202, 57, 58, 140, 123, 239, 116, 94, 72, 27, 177, 172, 35, 117, 219, 249, 139, 176, 98, 8, 99, 117, 227, 82, 72, 22, 113, 21, 200, 1, 123, 109, 58, 71, 94, 181, 27, 248, 139, 71, 67, 51, 237, 144, 168, 200, 96, 243, 160, 194, 198, 4, 246, 220, 39, 121, 219, 210, 200, 82, 152, 190, 248, 244, 216, 148, 82, 144, 35, 193 }
,
{ 230, 154, 138, 254, 28, 15, 40, 189, 79, 36, 188, 134, 78, 92, 17, 179, 79, 254, 58, 200, 238, 174, 169, 96, 96, 75, 110, 195, 75, 136, 41, 49, 34, 179, 68, 62, 194, 88, 251, 18, 124, 183, 152, 202, 20, 169, 125, 99, 167, 136, 43, 45, 101, 213, 245, 163, 32, 99, 136, 107, 236, 178, 156, 14, 101, 78, 77, 40, 36, 140, 58, 160, 0, 210, 106, 20, 124, 232, 119, 35, 159, 163, 185, 5, 120, 174, 202, 152, 18, 83, 3, 254, 5, 159, 12, 106, 108, 89, 146, 144, 162, 204, 49, 162, 159, 155, 182, 27, 55, 45, 62, 35, 208, 247, 40, 72, 166, 242, 224, 184, 69, 227, 182, 74, 131, 194, 181, 239, 28, 71, 127, 190, 69, 176, 106, 179, 76, 22, 206, 207, 67, 12, 242, 20, 4, 26, 92, 170, 13, 61, 98, 82, 32, 24, 157, 163, 218, 82, 146, 246, 153, 18, 180, 173, 194, 20, 96, 14, 42, 46, 222, 110, 59, 208, 130, 63, 235, 222, 233, 248, 27, 75, 74, 60, 99, 231, 223, 61, 255, 242, 25, 244, 0, 232, 12, 184, 207, 47, 240, 35, 180, 255, 33, 176 }
,
{ 17, 209, 49, 77, 32, 24, 45, 94, 26, 8, 190, 37, 81, 122, 165, 105, 214, 134, 138, 159, 216, 241, 52, 225, 245, 76, 106, 227, 228, 220, 61, 83, 154, 251, 161, 186, 19, 206, 27, 101, 109, 170, 138, 144, 37, 48, 249, 156, 182, 184, 59, 76, 60, 112, 45, 158, 188, 151, 130, 254, 36, 76, 172, 196, 71, 242, 200, 42, 192, 224, 192, 45, 182, 74, 180, 176, 205, 183, 100, 119, 111, 136, 125, 24, 248, 170, 183, 180, 65, 57, 206, 181, 133, 3, 194, 252, 246, 138, 38, 182, 107, 230, 228, 246, 49, 161, 125, 171, 88, 242, 220, 245, 122, 90, 224, 114, 4, 151, 38, 70, 208, 216, 251, 85, 220, 189, 33, 252, 152, 71, 143, 179, 46, 214, 154, 95, 14, 79, 10, 102, 65, 231, 46, 188, 65, 14, 46, 69, 71, 85, 139, 117, 45, 43, 202, 9, 68, 235, 178, 140, 50, 100, 63, 96, 208, 232, 191, 222, 55, 202, 69, 120, 177, 115, 52, 242, 129, 59, 229, 38, 184, 195, 155, 29, 73, 101, 239, 32, 38, 36, 56, 38, 81, 52, 211, 136, 9, 89, 24, 142, 128, 105, 73, 9 }
*/
};
/***********************************************************************************************************************************************************************************************/

    unsigned char rs_in[LENGTH], rs_out[LENGTH];
    int i, j;

    #pragma monitor start

    for (i = 0; i < N; ++i) {
        /* Copy data */
        for (j = 0; j < LENGTH; ++j) {
            rs_in[j] = (unsigned char) inputData[i][j];
        }

        reedsolomon(rs_out, rs_in);

        /* Number of errors to insert */
        for (j = 0; j < k[i]; ++j) {
            rs_out[pos[i][j]] = (unsigned char) noise[i][j];
        }

        reedsolomon(rs_in, rs_out);

        // Debug
        //printf("----------------------------------------------------------------------------------------------------\n\n");
        //printf("rs_out[]: { "); for (j = 0; j < LENGTH; ++j) printf("%d, ", (int)rs_out[j]); printf("}\n\n");
        //printf("rs_in[]: { ");  for (j = 0; j < LENGTH; ++j) printf("%d, ", (int)rs_in[j]);  printf("},\n\n");

        for (j = 0; j < LENGTH; ++j) {
            if ((int)rs_in[j] != expectedResult[i][j]) {
               //printf("[%d,%d]: %d - %d, ", i, j, (int)rs_in[j], expectedResult[i][j]); // Debug
               return 1;
            }
        }

    }

    #pragma monitor stop

    return 10;
}
