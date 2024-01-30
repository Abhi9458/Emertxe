/* Documentation
Name : ABHILASH MANOHAR JAVALI
Date : 28/02/2023
Description : Steganography
Sample Execution :
 [For Encoding]
emertxe@ubuntu:~/ECEP/Adv_c/Project/4-SkeletonCode$ ./a.out -e beautiful.bmp secret.txt stego.bmp
Selected encoding..
Read and validate is a success
Opened all the files successfully
Started Encoding
width = 1024
height = 768
Encoding is possible...
Copied header successfully
MAGIC STRING successfully
Successfully Encoded secret file extension size
Encoded secret file extension successfully
Encoded secret file size successfully
Encoded secret data successfully
Copied remaining bytes successfully
Completed encoding successfully

 [For Decoding]
emertxe@ubuntu:~/ECEP/Adv_c/Project/4-SkeletonCode$ ./a.out -d stego.bmp decode.txt
Selected decoding..
Read and validate is a success
Opened all the files successful
Started decoding..
MAGIC STRING decoded successfully
Succesfully decoded file extension size 
Decoded Secret File Extension Succesfully
Decoded secret file size Successfully
Decoded secret data Succuessfully
Completed decodeing Successfully
*/

#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include "decode.h"

/* Passing arguments through command line arguments */
int main(int argc, char *argv[])
{

   //checking for the argc
   if (argc >= 3)
   {

    // Function call for check operation type
    if (check_operation_type(argv) == e_encode)
    {
        printf("Selected encoding..\n");

        // Declare structure variable
        EncodeInfo encInfo;
        // Read and validate encode arguments 
        if (read_and_validate_encode_args(argv, &encInfo) == e_success)
        {
            printf("Read and validate is a success\n");
            

            // Function call for encoding
            if (do_encoding(&encInfo) == e_success)
            {
                printf("Completed encoding successfully\n");
            }
            else
            {
                printf("Failure: Encoding is unsuccessfull\n");
                return -1;
            }
        }
        else
        {
            printf("Read and validate is a failure\n");
            return -1;
        }
    }
    // Function call for check operation type
    else if (check_operation_type(argv) == e_decode)
    {
        printf("Selected decoding..\n");

        // Declare structure variables
        DecodeInfo decInfo;
        if (read_and_validate_decode_args(argv, &decInfo) == d_success)
        {
            printf("Read and validate is a success\n");
            

            // Function call for do decoding
            if (do_decoding(&decInfo) == d_success)
            {
                printf("Completed decodeing Successfully\n");
            }
            else
            {
                printf("Failed to decode\n");
                return -1;
            }
        }  
        else
        {
            printf("Read and validate decode arguments is a failure\n");
            return -1;
        }
    } 
    else
    {
        printf("Invalid option\nKindly pass for\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding: ./a.out -d stego.bmp decode.txt\n");
    }
  }
 else
 {
        printf("Error : Kindly pass for\n Encoding: 4 arguments\nDecoding: 3 arguments\n");
 }

    return 0;
}
