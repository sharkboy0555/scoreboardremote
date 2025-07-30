export function formatData(data: any): any {
    // Prepare data for sending to Node-RED
    return JSON.stringify(data);
}

export function validateInput(input: any): boolean {
    // Check if the input from the keypad is valid
    return typeof input === 'string' && input.trim() !== '';
}