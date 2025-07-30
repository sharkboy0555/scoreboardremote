import axios from 'axios';

class NodeRedAPI {
    private nodeRedUrl: string;

    constructor(nodeRedUrl: string) {
        this.nodeRedUrl = nodeRedUrl;
    }

    async sendData(data: any): Promise<void> {
        // Logic to send data to Node-RED
        try {
            await axios.post(`${this.nodeRedUrl}/remote`, data);
            console.log("Sent data to Node-RED:", data);
        } catch (error) {
            console.error("Error sending data to Node-RED:", error);
        }
    }

    async getData(key: string): Promise<any> {
        // Logic to get data from Node-RED
        try {
            const response = await axios.get(`${this.nodeRedUrl}/remote/${key}`);
            console.log("Received data from Node-RED:", response.data);
            return response.data;
        } catch (error) {
            console.error("Error getting data from Node-RED:", error);
            return null;
        }
    }
}

export default NodeRedAPI;