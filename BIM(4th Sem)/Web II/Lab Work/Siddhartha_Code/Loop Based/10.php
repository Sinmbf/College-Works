<!-- 10.	Use a loop to count the number of vowels in a string. -->

<?php
$str = "I am siddhartha";
$lower_str = strtolower($str);
$vowel_count = 0;
for ($i = 0; $i < strlen($str); $i++) {
    if ($lower_str[$i] == 'a' || $lower_str[$i] == 'e' || $lower_str[$i] == 'i' || $lower_str[$i] == 'o' || $lower_str[$i] == 'u')
        $vowel_count++;
}

echo "Number of vowels in the string: $str = $vowel_count";
?>