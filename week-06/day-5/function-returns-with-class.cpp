class Response {
public:
    signed char return_value;
    string answer;
};

Response RecognizeCommand(string c) {
    Response result;

    for (int i = 0; i < 11; i++) {
        if (command_token == ToDoCommands[i]) {
            result.return_value = i;
            result.answer = param_token;
            return result;
        }
    }
    result.return_value = -1;
    result.answer = "Error, command not recognized.";
    return result;
}