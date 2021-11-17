
#include "imgui_interface.h"

void ImGuiInit(SDL_Window* window, SDL_Renderer* renderer){
	ImGui::CreateContext();
  ImGui_ImplSDL2_InitForSDLRenderer(window);
  ImGui_ImplSDLRenderer_Init(renderer);
}

void ImGuiRenderInit(SDL_Window* window){
  ImGui_ImplSDLRenderer_NewFrame();
  ImGui_ImplSDL2_NewFrame(window);
  ImGui::NewFrame();
}

void ImGuiRenderClear(){
  ImGui::Render();
  ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiEvent(SDL_Event* event)
{
  ImGui_ImplSDL2_ProcessEvent(event);
}

void ImGuiExit(){
  ImGui_ImplSDLRenderer_Shutdown();
  ImGui_ImplSDL2_Shutdown();
}

void ImGuiShowData(Database* database, Info** info){

  static bool open = false;
  static char* value = '\0';

  ImGui::SetNextWindowSize(ImVec2(320, 400));
  ImGui::Begin("SQL Window", nullptr);

  ImGui::Text("Database status:"); 
  ImGui::SameLine();
  ImGui::TextColored(ImVec4(0,1,0,1), "%s", open ? "Open" : "Close"); 
  ImGui::SameLine();

  if(ImGui::SmallButton(open ? " Close Test Database " : " Open Test Database ")){
    if(!open){
      SQLInit(database, "../data/test.db");
      open = true;
    }
    else{
      SQLClose(database->db);
      open = false;
    }
  }

  if(open){
    ImGui::InputText("Query", database->sql_query, kQuerySize);
    ImGui::SameLine();
    if(ImGui::Button("Execute")){
      SQLExecute(database, info);
    }
    if(ImGui::CollapsingHeader("Test")){
      ShowTableData(info);
    }
  }

  ImGui::End();
}

void ShowTableData(Info** head){

  if(nullptr != *head){

    for(Info* node = *head; node != nullptr; node = node->next){
      ImGui::Text("Name: %s", node->colname);
      ImGui::Text("Value: %s", node->value);
    }
    ImGui::Spacing();
  }
  else return;

}

