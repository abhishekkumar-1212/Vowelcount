## Run the helper, server, and client
1. Start the Server

cd server
./server 8080


2. Start the Helper

cd helper
./helper 127.0.0.1 8080


3. Run the Client

cd client
./client 127.0.0.1 8080

## output 
Letter aA : 3
Letter eE : 9
Letter iI : 9
Letter oO : 8
Letter uU : 4

## IMPORTANT FIRST STEP : 
3. Running the Project:
Step 1: Compile the code
cd client
make  
 # This will compile client.c, client_utils.c, and link with the shared queue files.

cd ../server
make  
 # This will compile server.c, server_utils.c, and link with the shared queue files.

cd ../helper
make   
# This will compile helper.c, helper_utils.c.


## Step 2: Start the server
cd server
./server

## Step 3: Start the helper
cd helper
./helper

## Step 4: Run the client
cd client
./client

## CLIENT PROCESS INVOLVE : 
The client will:

Read data from input.txt.
Send it to the helper for encoding.
Send the encoded data to the server for processing.
Receive the vowel counts from the server.
Write the results to receivedVowelCount.txt.

## Expected Output:
Totals
Letter aA : 4
Letter eE : 4
Letter iI : 3
Letter oO : 2
Letter uU : 1








