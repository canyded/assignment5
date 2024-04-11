#include <iostream>
#include <string>

class Data {
public:
    std::string type;
    std::string content;

    Data(const std::string& data_type, const std::string& data_content) : type(data_type), content(data_content) {}
};

class DataProcessor {
public:
    virtual void process_data(const Data& data) = 0;
};


class TextData : public Data {
public:
    TextData(const std::string& content) : Data("text", content) {}
};

class AudioData : public Data {
public:
    AudioData(const std::string& content) : Data("audio", content) {}
};

class VideoData : public Data {
public:
    VideoData(const std::string& content) : Data("video", content) {}
};

class TextDataProcessor : public DataProcessor {
public:
    void process_data(const Data& data) override {
        std::cout << "Processing text data: " << data.content << std::endl;
    }
};

class AudioDataProcessor : public DataProcessor {
public:
    void process_data(const Data& data) override {
        std::cout << "Processing audio data: " << data.content << std::endl;
    }
};

class VideoDataProcessor : public DataProcessor {
public:
    void process_data(const Data& data) override {
        std::cout << "Processing video data: " << data.content << std::endl;
    }
};

class DataProcessorCreator {
private:
    DataProcessor* processor;

public:
    DataProcessorCreator(DataProcessor* initial_processor) : processor(initial_processor) {}

    void set_processor(DataProcessor* new_processor) {
        processor = new_processor;
    }

    void process_data(const Data& data) {
        processor->process_data(data);
    }
};


int main() {
    TextDataProcessor text_processor;
    AudioDataProcessor audio_processor;
    VideoDataProcessor video_processor;

    DataProcessorCreator processor_creator(&text_processor);

    TextData text_data("This is a text.");
    AudioData audio_data("This is an audio clip.");
    VideoData video_data("This is a video.");

    processor_creator.process_data(text_data);
    processor_creator.process_data(audio_data);
    processor_creator.process_data(video_data);

    processor_creator.set_processor(&audio_processor);
    processor_creator.process_data(text_data);
    processor_creator.process_data(audio_data);
    processor_creator.process_data(video_data);

    return 0;
}
