<?php
// chat with openAI gpt-4 LLM
$yourApiKey = getenv('YOUR_API_KEY');
$client = OpenAI::client($yourApiKey);
$result = $client->chat()->create([
    'model' => 'gpt-4',
    'messages' => [
        ['role' => 'user', 'content' => 'Hello!'],
    ],
]);

// grab the user id
$id = $result->choices[0]->message->content;

// Check database
$query  = "SELECT first_name, last_name FROM users WHERE user_id = '$id';";
$result = mysqli_query($GLOBALS["___mysqli_ston"],  $query );

// Get results
while( $row = mysqli_fetch_assoc( $result ) ) {
	// Get values
	$first = $row["first_name"];
	$last  = $row["last_name"];

	// Feedback for end user
	$html .= "<pre>ID: {$id}<br />First name: {$first}<br />Surname: {$last}</pre>";
}

mysqli_close($GLOBALS["___mysqli_ston"]);
?>
